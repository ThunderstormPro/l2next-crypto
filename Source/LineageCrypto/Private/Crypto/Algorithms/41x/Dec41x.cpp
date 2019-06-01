#include "Crypto/Algorithms/41x/Dec41x.h"

void Dec41x::SetInputData(const char* buffer)
{
	AlgorithmBase::SetInputData(buffer);
}

void Dec41x::GetExecResult(char*& result)
{
	result = new char[4] { 'O', 'K' };
}

void Dec41x::Reset()
{
	AlgorithmBase::Reset();
	// Reset op.
}
