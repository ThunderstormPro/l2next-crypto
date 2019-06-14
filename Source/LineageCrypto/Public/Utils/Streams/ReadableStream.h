#ifndef H_READABLE_STREAM
#define H_READABLE_STREAM

#include <vector>
#include <iostream>
#include <memory>
#include "DuplexStream.h"
#include "WritableStream.h"
#include "Traits/Readable.h"
#include "Traits/Pipable.h"
#include "Structs/FileStreamOptions.h"
#include "Structs/BufStreamOptions.h"

namespace LineageCryptoStreams {

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
		virtual void Exec(std::shared_ptr<std::iostream> _self) final;

	private:
		StreamOptions& options;
	};
}
#endif
