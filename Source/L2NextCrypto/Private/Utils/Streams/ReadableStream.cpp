#include "Utils/Streams/ReadableStream.h"

using namespace L2NextCryptoStreams;

ReadableStream::ReadableStream(const ReadableStream& _self) 
	: options(_self.options)
{
}

ReadableStream::ReadableStream(StreamOptions& options)
	: options(options)
{
}

ReadableStream::~ReadableStream()
{
}

void ReadableStream::Exec(std::shared_ptr<std::iostream> _self)
{
	switch (options.GetType())
	{
	case EStreamTypes::FILE:
		ReadFileStream(options);
		break;
	case EStreamTypes::BUFFER:
		ReadBufferedStream(options);
		break;
	default:
		break;
	}

	Propagate(GetPipe(), nextStream);
}
