#include "Utils/Streams/DuplexStream.h"

using namespace L2NextCryptoStreams;

DuplexStream::DuplexStream()
{
}

DuplexStream::DuplexStream(const DuplexStream & _self)
{
}

DuplexStream::~DuplexStream()
{
}

void DuplexStream::Exec(std::shared_ptr<std::iostream> stream)
{
	// Should be streaming further by default.
	bIsStreaming = true;

	// Can be stopped from inside the transform.
	nextStream = Transform(stream);

	// Propagate to the next piped stream.
	TTransformable::Propagate(GetPipe(), nextStream);
}
