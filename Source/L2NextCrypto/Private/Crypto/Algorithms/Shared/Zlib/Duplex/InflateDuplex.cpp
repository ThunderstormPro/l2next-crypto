#include "Crypto/Algorithms/Shared/ZLib/Duplex/InflateDuplex.h"
#include <zlib.h>
#include <assert.h>

std::stringstream& InflateDuplex::Transform(std::stringstream& input)
{
	int returnCode;
	SInflatedChunk inflatedChunk;
	unsigned int currentBlockSize = 0;

	z_stream strm;
	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	returnCode = inflateInit(&strm);

	if (returnCode != Z_OK)
	{
		Exec_OnInflateFailed(returnCode);
	}

	input.seekg(0, std::ios::end);
	inflatedChunk.total = input.tellg();
	input.seekg(0, std::ios::beg);
	
	do {
		input.read(in.data(), CHUNK);

		strm.avail_in = input.gcount();
		inflatedChunk.current += strm.avail_in;

		if (input.bad()) {
			(void)inflateEnd(&strm);
			Exec_OnInflateFailed(Z_ERRNO);
		}

		if (strm.avail_in == 0)
			break;

		strm.next_in = (Bytef*)in.data();

		Exec_OnInflateChunk(inflatedChunk);

		do {
			strm.avail_out = CHUNK;
			strm.next_out = (Bytef*)out.data();
			returnCode = inflate(&strm, Z_NO_FLUSH);

			assert(returnCode != Z_STREAM_ERROR);

			switch (returnCode) {
			case Z_NEED_DICT:
				returnCode = Z_DATA_ERROR;
			case Z_DATA_ERROR:
			case Z_MEM_ERROR:
				(void)inflateEnd(&strm);
				Exec_OnInflateFailed(returnCode);
			}

			currentBlockSize = CHUNK - strm.avail_out;
			current.write(out.data(), currentBlockSize);

			if (current.bad()) {
				(void)inflateEnd(&strm);
				Exec_OnInflateFailed(Z_ERRNO);
			}

		} while (strm.avail_out == 0);
	} while (returnCode != Z_STREAM_END);
	
	(void)inflateEnd(&strm);
	return current;
}