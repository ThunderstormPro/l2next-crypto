#include "Crypto/Algorithms/41x/Duplex/Ver41xDecDuplex.h"
#include <sstream>
#include <fstream>
#include <algorithm>

const int modulusBytes[] = {
	0x97, 0xdf, 0x39, 0x84, 0x72, 0xdd, 0xf7, 0x37,
	0xef, 0x0a, 0x0c, 0xd1, 0x7e, 0x8d, 0x17, 0x2f,
	0x0f, 0xef, 0x16, 0x61, 0xa3, 0x8a, 0x8a, 0xe1,
	0xd6, 0xe8, 0x29, 0xbc, 0x1c, 0x6e, 0x4c, 0x3c,
	0xfc, 0x19, 0x29, 0x2d, 0xda, 0x9e, 0xf9, 0x01,
	0x75, 0xe4, 0x6e, 0x73, 0x94, 0xa1, 0x88, 0x50,
	0xb6, 0x41, 0x7d, 0x03, 0xbe, 0x6e, 0xea, 0x27,
	0x4d, 0x3e, 0xd1, 0xdd, 0xe5, 0xb5, 0xd7, 0xbd,
	0xe7, 0x2c, 0xc0, 0xa0, 0xb7, 0x1d, 0x03, 0x60,
	0x86, 0x55, 0x63, 0x38, 0x81, 0x79, 0x3a, 0x02,
	0xc9, 0xa6, 0x7d, 0x9e, 0xf2, 0xb4, 0x5e, 0xb7,
	0xc0, 0x8d, 0x4b, 0xe3, 0x29, 0x08, 0x3c, 0xe4,
	0x50, 0xe6, 0x8f, 0x78, 0x67, 0xb6, 0x74, 0x93,
	0x14, 0xd4, 0x05, 0x11, 0xd0, 0x9b, 0xc5, 0x74,
	0x45, 0x51, 0xba, 0xa8, 0x6a, 0x89, 0xdc, 0x38,
	0x12, 0x3d, 0xc1, 0x66, 0x8f, 0xd7, 0x2d, 0x83
};
constexpr unsigned long privateExponent = 0x35;

constexpr int ReverseBytes(int value)
{
	char* bytes = (char*)&value;
	return (int)bytes[3] | ((int)bytes[2] << 8) | ((int)bytes[1] << 16) | ((int)bytes[0] << 24);
}

/*
char * ReverseBytes(char *start, int size)
{
	char *istart = start, *iend = istart + size;
	std::reverse(istart, iend);
	return istart;
}*/

Ver41xDecDuplex::Ver41xDecDuplex(Ver41xParams& params)
	: params(params)
{



}

Ver41xDecDuplex::~Ver41xDecDuplex()
{

}

int Ver41xDecDuplex::GetAvailableReadBytes()
{
	return size - position;
}

bool Ver41xDecDuplex::EnsureFilled(const std::shared_ptr<std::iostream>& stream)
{
	//std::cout << "position ::" << position << " = " << "size ::" << size << std::endl;

	if (position == size)
	{
		size_t remainingBytes = buffer.size();
		//std::cout << "Reading.." << std::endl;
		while (remainingBytes > 0)
		{
			stream->read(buffer.data(), remainingBytes);
			std::streamsize readBytes = stream->gcount();

			if (readBytes < 0)
			{
				std::cout << "readBytes < 0 CHUNK ERROR" << std::endl;
				return false;
			}

			remainingBytes -= readBytes;
		}

		try
		{
			mpz_import(readBlock, 128, 1, 1, 0, 0, buffer.data());
			mpz_powm_ui(modPowedBlock, readBlock, params.privateExponent, modulus);
			mpz_export(decBuffer, &count, 1, 4, 1, 0, modPowedBlock);
			
		}
		catch (std::exception e)
		{
			std::cout << "CONV ERROR" << std::endl;
		}

		size = decBuffer[3] & 0xff;
		//memset(decBuffer.data(), 0, 128); // TODO: нужно ли?
	
		if (size > 124)
		{
			std::cout << " size > 124 CHUNK ERROR" << std::endl;
			return false;
		}

		startPosition = 128 - size - ((124 - size) % 4);
		position = 0;

		return true;
	}
	
	return true;
}

std::shared_ptr<std::iostream> Ver41xDecDuplex::Transform(const std::shared_ptr<std::iostream>& stream)
{
	// 1. Decrypt.
	std::stringstream decrypted;

	mpz_init(modulus);
	mpz_import(modulus, BLOCK_SIZE, 1, 1, 0, 0, params.publicModulus.data());
	mpz_init(readBlock);
	mpz_init(modPowedBlock);


	//std::vector<char> zlibHeader(128, 0);
	stream->read(buffer.data(), buffer.size());

	mpz_import(readBlock, 128, 1, 1, 0, 0, buffer.data());
	mpz_powm_ui(modPowedBlock, readBlock, params.privateExponent, modulus);
	mpz_export(decBuffer, &count, 1, 4, 1, 0, modPowedBlock);

	size = ReverseBytes(decBuffer[3]);

	std::cout << "Unpacked size detected :: " << size << std::endl;           
	/*startPosition = 128 - size - ((124 - size) % 4);
	unpackedSize = ((unsigned int *)&((char *)decBuffer)[startPosition])[0];

	

	// Read the actual file contents without the header block.
	while (!stream->eof())
	{
		if (!EnsureFilled(stream))
		{
			continue;
		}

		//stream->read(decBuffer, startPosition);

		int readChunkSize = std::min((int)buffer.size(), (int)GetAvailableReadBytes());

		decrypted.write((char*)decBuffer, readChunkSize);
		
		position += readChunkSize; 
	}

//	decrypted.clear();

	// 2. Decompress.
	std::stringstream decompressed;

	char* unpackedData = new char[unpackedSize];
	z_stream unpackStream;
	unpackStream.zalloc = Z_NULL;
	unpackStream.zfree = Z_NULL;
	unpackStream.opaque = Z_NULL;
	unpackStream.avail_in = (uInt)decrypted.str().size();
	unpackStream.next_in = (Bytef *)decrypted.str().c_str();
	unpackStream.avail_out = unpackedSize;
	unpackStream.next_out = (Bytef *)unpackedData;

	inflateInit(&unpackStream);
	inflate(&unpackStream, Z_NO_FLUSH);
	inflateEnd(&unpackStream);

	std::ofstream output("D:\\test\\decompressed.dat", std::ios::binary);
	output.write(unpackedData, unpackedSize);
	output.close();
	mpz_clear(modulus);
	mpz_clear(readBlock);
	mpz_clear(modPowedBlock);
	delete[] unpackedData;

	//std::ofstream ss("D:\\test\\decrypted.dat", std::ios::binary);

	//ss.write(decrypted.str().data(), decrypted.str().size());
	*/
	return stream;
}