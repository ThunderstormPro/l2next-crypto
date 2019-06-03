#include "Crypto/Algorithms/Base/AlgorithmBase.h"

EHeaderVersion AlgorithmBase::GetVersion()
{
	return EHeaderVersion::NOT_IMPL;
}

void AlgorithmBase::SetBuffer(const char* buffer)
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