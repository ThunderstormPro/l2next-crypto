#include "Utils/Streams/Factory/StreamFactory.h"

using namespace L2NextCryptoStreams;

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

std::shared_ptr<SFileStreamOptions> L2NextCryptoStreams::StreamFactory::Options(const SFileStreamOptions& stream)
{
	return Make<SFileStreamOptions>(stream);
}

std::shared_ptr<SBufStreamOptions> L2NextCryptoStreams::StreamFactory::Options(const SBufStreamOptions & stream)
{
	return  Make<SBufStreamOptions>(stream);
}
