#include "Utils/Streams/WritableStream.h"

using namespace L2NextCryptoStreams;

void WritableStream::Exec(std::shared_ptr<std::iostream> stream)
{
	switch (options.GetType())
	{
	case EStreamTypes::FILE:
		WriteFile(options, stream);
		break;
	case EStreamTypes::BUFFER:
		WriteBuffer(options, stream);
		break;
	default:
		break;
	}
};