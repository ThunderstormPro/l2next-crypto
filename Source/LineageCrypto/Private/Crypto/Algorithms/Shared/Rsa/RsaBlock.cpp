#include "Crypto/Algorithms/Shared/Rsa/RsaBlock.h"

RSABlock::RSABlock(const std::shared_ptr<std::iostream>& stream, size_t bufferSize)
	: stream(stream)
	, bufferSize(bufferSize)
{
}

int RSABlock::ReverseBytes(int value)
{
	const auto bytes = reinterpret_cast<char*>(&value);
	return static_cast<int>(bytes[3])
		| (static_cast<int>(bytes[2]) << 8)
		| (static_cast<int>(bytes[1]) << 16)
		| (static_cast<int>(bytes[0]) << 24);
}
