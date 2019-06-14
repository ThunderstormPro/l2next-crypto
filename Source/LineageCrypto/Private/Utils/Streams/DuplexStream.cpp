#include "Utils/Streams/DuplexStream.h"

using namespace LineageCryptoStreams;

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
	nextStream = Transform(stream);
	TTransformable::Propagate(GetPipe(), nextStream);
}
