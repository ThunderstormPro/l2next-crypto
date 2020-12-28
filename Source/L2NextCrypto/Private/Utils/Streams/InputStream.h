#ifndef H_INPUT_STREAM
#define H_INPUT_STREAM

#include <memory>
#include <string>
#include <sstream>
#include "DuplexStream.h"

constexpr int BUFFER_SIZE = 8192;

namespace L2NextCryptoStreams
{
	class InputStream
	{
	public:
		InputStream(const std::stringstream& stream)
		{
			char buffer[BUFFER_SIZE];

			stream.rdbuf()->pubsetbuf(buffer, BUFFER_SIZE);

			current << stream.rdbuf();
		}

		DuplexStream& operator >> (DuplexStream& pipe)
		{
			pipe.next << pipe.Transform(current).rdbuf();
			return pipe;
		}
	private:
		std::stringstream current;
	};
}
#endif
