#ifndef H_OUTPUT_STREAM
#define H_OUTPUT_STREAM

#include <sstream>
#include <memory>
#include <vector>
#include <streambuf>
#include "DuplexStream.h"

namespace L2NextCryptoStreams
{
	class OutputStream : public DuplexStream
	{
	public:
		OutputStream()
		{}

		std::vector<unsigned char> GetBuffer()
		{
			std::vector<unsigned char> buffer{ std::istreambuf_iterator<char>(next), {} };

			return buffer;
		};
	};
}

#endif // H_OUTPUT_STREAM
