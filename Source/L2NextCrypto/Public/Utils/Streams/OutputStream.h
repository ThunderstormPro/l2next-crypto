#ifndef H_OUTPUT_STREAM
#define H_OUTPUT_STREAM

#include <sstream>
#include <memory>
#include <vector>
#include <iostream>
#include <streambuf>
#include "DuplexStream.h"

namespace L2NextCryptoStreams
{
	class OutputStream : public DuplexStream
	{
	public:
		OutputStream()
		{}

		std::string GetResult()
		{
			return next.str();
		};
	};
}

#endif // H_OUTPUT_STREAM
