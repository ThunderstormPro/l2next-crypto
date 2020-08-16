#ifndef H_DUPLEX_STREAM
#define H_DUPLEX_STREAM

#include <memory>
#include <sstream>

namespace L2NextCryptoStreams
{
	class DuplexStream
	{
	public:
		DuplexStream()
		{}

		virtual std::stringstream& Transform(std::stringstream& input)
		{
			return input;
		};

		DuplexStream& operator >> (DuplexStream& pipe)
		{
			pipe.next << pipe.Transform(next).rdbuf();
			return pipe;
		}

		std::stringstream current;
		std::stringstream next;
	};
}

#endif // H_DUPLEX_STREAM
