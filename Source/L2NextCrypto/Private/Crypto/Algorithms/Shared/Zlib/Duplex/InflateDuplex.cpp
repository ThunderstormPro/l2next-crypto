#include "Crypto/Algorithms/Shared/ZLib/Duplex/InflateDuplex.h"
#include <zlib.h>
#include <assert.h>


std::stringstream& InflateDuplex::Transform(std::stringstream& input)
{
	int ret;
	unsigned have;
	z_stream strm;
	char in[CHUNK];
	char out[CHUNK];

	/* allocate deflate state */
	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	ret = inflateInit(&strm);

	if (ret != Z_OK)
	{
		throw ret;
	}
	
	/* decompress until deflate stream ends or end of file */
	do {
		input.read(in, CHUNK);

		strm.avail_in = input.gcount();
		if (input.bad()) {
			(void)inflateEnd(&strm);
			throw Z_ERRNO;
		}
		if (strm.avail_in == 0)
			break;
		strm.next_in = (Bytef*)in;
		/* run inflate() on input until output buffer not full */
		do {
			strm.avail_out = CHUNK;
			strm.next_out = (Bytef*)out;
			ret = inflate(&strm, Z_NO_FLUSH);

			assert(ret != Z_STREAM_ERROR);

			switch (ret) {
			case Z_NEED_DICT:
				ret = Z_DATA_ERROR;     /* and fall through */
			case Z_DATA_ERROR:
			case Z_MEM_ERROR:
				(void)inflateEnd(&strm);
				throw ret;
			}
			have = CHUNK - strm.avail_out;

			current.write(out, have);

			if (current.bad()) {
				(void)inflateEnd(&strm);
				throw Z_ERRNO;
			}

		} while (strm.avail_out == 0);

		/* done when inflate() says it's done */
	} while (ret != Z_STREAM_END);
	/* clean up and return */
	(void)inflateEnd(&strm);
	return current;
}