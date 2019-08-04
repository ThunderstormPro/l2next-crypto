#include "Crypto/Algorithms/Shared/ZLib/Duplex/InflateDuplex.h"

std::shared_ptr<std::iostream> InflateDuplex::Transform(const std::shared_ptr<std::iostream>& stream)
{
	const auto decrypted = static_pointer_cast<std::stringstream>(stream);
	const auto decompressed = std::make_shared<std::stringstream>();

	int status = 0;

	// Reference : https://stackoverflow.com/questions/1374468/stringstream-string-and-char-conversion-confusion
	const std::string& tmp = decrypted->str();
	const char* nextAvailInBuff = tmp.c_str();

	std::vector<char> decompressedData(schema.fileSize);

	z_stream decompressedStream;
	decompressedStream.zalloc = Z_NULL;
	decompressedStream.zfree = Z_NULL;
	decompressedStream.opaque = Z_NULL;
	decompressedStream.avail_in = (uInt)decrypted->str().size();
	decompressedStream.next_in = (Bytef*)nextAvailInBuff;
	decompressedStream.avail_out = (uInt)decompressedData.size();
	decompressedStream.next_out = (Bytef*)decompressedData.data();

	inflateInit(&decompressedStream);
	status = inflate(&decompressedStream, Z_NO_FLUSH);
	inflateEnd(&decompressedStream);

	std::cout << "zlib decompression status: " << status << std::endl;

	if (decompressedStream.msg)
	{
		std::cout << "zlib decompression report msg: " << decompressedStream.msg << std::endl;
	}

	decompressed->write(decompressedData.data(), decompressedData.size());
	return decompressed;
}
