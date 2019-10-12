#include "Crypto/Algorithms/Shared/ZLib/Duplex/InflateDuplex.h"
#include <zlib.h>

std::shared_ptr<std::iostream> InflateDuplex::Transform(const std::shared_ptr<std::iostream>& stream)
{
	const auto decrypted = static_pointer_cast<std::stringstream>(stream);
	const auto decompressed = std::make_shared<std::stringstream>();

	int status = 0;

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

	if (status < 0)
	{
		schema.errorMsg = decompressedStream.msg;
		Exec_OnInflateFailed(SZlibResult{ status, decompressedStream.msg });

		Stop();
		return nullptr;
	}

	decompressed->write(decompressedData.data(), decompressedData.size());
	return decompressed;
}
