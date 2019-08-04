#include "Crypto/Algorithms/Shared/Rsa/RsaBlock.h"

RSABlock::RSABlock(const std::shared_ptr<std::iostream>& stream, size_t bufferSize)
	: stream(stream)
	, bufferSize(bufferSize)
{
}