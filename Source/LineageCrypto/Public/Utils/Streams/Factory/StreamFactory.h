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
		// Streams smart pointer wrapper.
		static std::shared_ptr<ReadableStream> Make(const ReadableStream& stream);
		static std::shared_ptr<DuplexStream> Make(const DuplexStream& stream);
		static std::shared_ptr<WritableStream> Make(const WritableStream& stream);

		// Stream options smart pointer wrapper.
		static std::shared_ptr<SFileStreamOptions> Options(const SFileStreamOptions& stream);
		static std::shared_ptr<SBufStreamOptions> Options(const SBufStreamOptions& stream);

		template<typename T>
		static std::shared_ptr<T> Make(const T& obj) {
			return std::make_shared<T>(obj);
		};
	};
}


#endif // H_STREAM_FACTORY
