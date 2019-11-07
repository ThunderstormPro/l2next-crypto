#include "Crypto/Algorithms/Shared/Rsa/RsaBlock.h"

RSABlock::RSABlock(std::stringstream& stream, size_t bufferSize)
	: stream(stream)
	, bufferSize(bufferSize)
{
}