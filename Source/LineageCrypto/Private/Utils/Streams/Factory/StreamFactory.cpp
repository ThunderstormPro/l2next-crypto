#include "Utils/Streams/Factory/StreamFactory.h"

using namespace LineageCryptoStreams;

std::shared_ptr<ReadableStream> StreamFactory::Make(const ReadableStream & stream)
{
	return Make<ReadableStream>(stream);
}

std::shared_ptr<DuplexStream> StreamFactory::Make(const DuplexStream & stream)
{
	return Make<DuplexStream>(stream);
}

std::shared_ptr<WritableStream> StreamFactory::Make(const WritableStream & stream)
{
	return Make<WritableStream>(stream);
}
