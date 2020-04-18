#ifndef H_OUTPUT_STREAM
#define H_OUTPUT_STREAM

#include <sstream>
#include <memory>
#include <streambuf>
#include "DuplexStream.h"

namespace L2NextCryptoStreams
{
	class OutputStream: public DuplexStream
	{
	public:
		OutputStream()
		{}

		std::string GetData()
		{
			return std::string(next.str().c_str(), next.str().size());
		};
	};
}

#endif // H_OUTPUT_STREAM
