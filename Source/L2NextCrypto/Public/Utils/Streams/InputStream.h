#ifndef H_INPUT_STREAM
#define H_INPUT_STREAM

#include <memory>
#include <string>
#include <sstream>
#include "DuplexStream.h"

namespace L2NextCryptoStreams
{
	class InputStream
	{
		public:
			InputStream(const char* data, const int size)
				: current(std::string(data, size)) {}

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
