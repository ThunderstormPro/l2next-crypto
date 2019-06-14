#ifndef H_STREAM_FACTORY
#define H_STREAM_FACTORY

#include <memory>
#include <type_traits>
#include "Utils/Streams/ReadableStream.h"
#include "Utils/Streams/DuplexStream.h"
#include "Utils/Streams/WritableStream.h"

namespace LineageCryptoStreams {

	class StreamFactory
	{
	public:
		static std::shared_ptr<ReadableStream> Make(const ReadableStream& stream);
		static std::shared_ptr<DuplexStream> Make(const DuplexStream& stream);
		static std::shared_ptr<WritableStream> Make(const WritableStream& stream);

		template<typename T>
		static std::shared_ptr<T> Make(const T& stream) {
			return std::make_shared<T>(stream);
		};
	};
}


#endif // H_STREAM_FACTORY
