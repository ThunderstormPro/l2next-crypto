#include "Utils/Streams/ReadableStream.h"

std::shared_ptr<ReadableStream> ReadableStream::Create(const std::string & fname)
{
	return std::make_shared<ReadableStream>(fname);
}

std::shared_ptr<DuplexStream> ReadableStream::Pipe(std::shared_ptr<DuplexStream> stream)
{
	duplexPipePtr = stream;
	return stream;
};

std::shared_ptr<WritableStream> ReadableStream::Pipe(std::shared_ptr<WritableStream> stream)
{
	wstreamPipePtr = stream;
	return stream;
};

void ReadableStream::OnRead()
{
	if (duplexPipePtr)
	{
		duplexPipePtr->Transform();
	}

	if (wstreamPipePtr)
	{
		wstreamPipePtr->Transform();
	}
}