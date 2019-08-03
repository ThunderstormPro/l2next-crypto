#include "Crypto/Algorithms/Base/Algorithm.h"

const DuplexTypes& Algorithm::GetDuplex() const
{
	return duplex;
}

EHeaderVersion Algorithm::GetVersion() const
{
	return version;
}

void Algorithm::SetBuffer(const char* inBuffer)
{
	buffer = inBuffer;
}

const char* Algorithm::GetBuffer() const
{
	return buffer;
}

void Algorithm::Reset()
{
	delete buffer;
}