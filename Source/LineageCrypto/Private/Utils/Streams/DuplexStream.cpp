#include "Utils/Streams/DuplexStream.h"

DuplexStream::DuplexStream(std::string name) : name(name)
{
}

std::shared_ptr<DuplexStream> DuplexStream::Create(std::string name)
{
	return std::make_shared<DuplexStream>(name);
}

void DuplexStream::Transform()
{
	std::cout << "From DuplexStream" << name << "\n";

	if (duplexPipePtr)
	{
		duplexPipePtr->Transform();
	}

	if (wstreamPipePtr)
	{
		wstreamPipePtr->Transform();
	}

}