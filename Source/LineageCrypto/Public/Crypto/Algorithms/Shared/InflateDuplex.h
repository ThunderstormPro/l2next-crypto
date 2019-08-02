#ifndef H_DEFLATE_DUPLEX
#define H_DEFLATE_DUPLEX

#include <memory>
#include <vector>
#include "Utils/Streams/DuplexStream.h"

using namespace::LineageCryptoStreams;

class InflateDuplex : public DuplexStream
{
	std::shared_ptr<std::iostream> Transform(const std::shared_ptr<std::iostream>& stream) final
	{
		const auto decompressed = std::make_shared<std::stringstream>();

		/*int decompressedSize = 0;
		// TODO Parse zlib header in a proper way using bit offset mask.
		decompressedSize = ((unsigned int *)&(header.GetBuffer())[header.GetBlockStartPosition()])[0];
		const int zlibOffset = 4;

		int zlibErrorCode = 0;

		// WTF lol :D
		// Reference : https://stackoverflow.com/questions/1374468/stringstream-string-and-char-conversion-confusion
		const std::string& tmp = decrypted->str();
		const char* cstr = tmp.c_str();
	
		std::vector<char> decompressedData(decompressedSize);
		z_stream unpackStream;
		unpackStream.zalloc = Z_NULL;
		unpackStream.zfree = Z_NULL;
		unpackStream.opaque = Z_NULL;
		unpackStream.avail_in = (uInt)decrypted->str().size();
		unpackStream.next_in = (Bytef*)cstr;
		unpackStream.avail_out = (uInt)decompressedSize;
		unpackStream.next_out = (Bytef*)decompressedData.data();

		inflateInit(&unpackStream);
		zlibErrorCode = inflate(&unpackStream, Z_NO_FLUSH);
		inflateEnd(&unpackStream);

		std::cout << "zlib decompression status: " << zlibErrorCode << std::endl;

		if (unpackStream.msg != nullptr)
		{
			std::cout << "zlib decompression report msg: " << unpackStream.msg << std::endl;
		}

		decompressed->write(decompressedData.data(), decompressedData.size());
		*/
		return decompressed;
	}

};

#endif // H_DEFLATE_DUPLEX