#ifndef H_READABLE_STREAM
#define H_READABLE_STREAM

#include <memory>
#include "DuplexStream.h"
#include "WritableStream.h"
#include "Traits/Readable.h"
#include "Traits/Pipable.h"
#include "Structs/BufStreamOptions.h"

namespace L2NextCryptoStreams {

	class ReadableStream
		: public TReadable
		, public TPipable<DuplexStream, WritableStream>
	{
	public:
		using PipableTypes = TPipable<DuplexStream, WritableStream>;
		
		ReadableStream(const ReadableStream& _self);
		ReadableStream(StreamOptions& options);
		~ReadableStream();

	protected:
		void Exec(std::shared_ptr<std::iostream> _self) override final;

	private:
		StreamOptions& options;
	};
}
#endif
