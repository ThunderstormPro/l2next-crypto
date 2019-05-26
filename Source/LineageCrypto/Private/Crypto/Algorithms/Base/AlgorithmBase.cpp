#include "Crypto/Algorithms/Base/AlgorithmBase.h"

void AlgorithmBase::SetInputData(const char * buffer)
{
	_buffer = buffer;
}

const char* AlgorithmBase::GetBuffer() const
{
	return _buffer;
}

void AlgorithmBase::Reset()
{
	delete _buffer;
}
