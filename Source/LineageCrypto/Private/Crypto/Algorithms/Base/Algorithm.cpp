#include "Crypto/Algorithms/Base/Algorithm.h"

EHeaderVersion Algorithm::GetVersion()
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

void Algorithm::GetResult(ECryptType type, char *& outBuffer)
{
	const char* inBuffer = GetBuffer();

	if (type == ECryptType::ENC && duplex.encrypt != nullptr)
	{
		return duplex.encrypt->Transform(inBuffer, outBuffer);
	}

	if (type == ECryptType::DEC && duplex.decrypt != nullptr)
	{
		return duplex.decrypt->Transform(inBuffer, outBuffer);
	}
}

void Algorithm::Reset()
{
	delete buffer;
}