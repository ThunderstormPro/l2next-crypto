#include "Crypto/Algorithms/Shared/Rsa/RsaEncryptedBlock.h"

RSAEncryptedBlock::RSAEncryptedBlock(const std::shared_ptr<std::iostream>& stream, std::vector<unsigned char> mod, unsigned long exp, size_t bufferSize)
	: RSABlock(stream, bufferSize)
{
	// Initialize buffers.
	importBuffer = std::vector<char>(bufferSize, 0);
	exportBuffer = std::vector<int>(bufferSize / sizeof(int), 0);

	stream->read(importBuffer.data(), importBuffer.size());

	// Initializing public modulus.
	mpz_init(modulus);
	mpz_import(modulus, bufferSize, 1, 1, 0, 0, mod.data());

	// Initializing readable block.
	mpz_init(readBlock);
	mpz_import(readBlock, bufferSize, 1, 1, 0, 0, importBuffer.data());

	// Perform pow operation on read block.
	mpz_init(modPowedBlock);
	mpz_powm_ui(modPowedBlock, readBlock, exp, modulus);

	// Do we need this?
	count = 32;
	exportBuffer.resize(128);

	mpz_export(exportBuffer.data(), &count, 1, sizeof(int), 1, 0, modPowedBlock);
}

RSAEncryptedBlock::~RSAEncryptedBlock()
{
	mpz_clear(modulus);
	mpz_clear(readBlock);
	mpz_clear(modPowedBlock);
}

size_t RSAEncryptedBlock::GetBlockSize()
{
	return ReverseBytes(exportBuffer.at(0)); //((char*)exportBuffer.data())[3] & 0xff;
}

size_t RSAEncryptedBlock::GetBufferSize()
{
	if (static_cast<size_t>(stream->gcount()) == exportBuffer.size())
	{
		return exportBuffer.size();
	}

	return stream->gcount();
}

char* RSAEncryptedBlock::GetBuffer()
{
	return reinterpret_cast<char*>(exportBuffer.data());
}

size_t RSAEncryptedBlock::GetBlockStartPosition()
{
	return bufferSize - GetBlockSize() - (124 - GetBlockSize()) % 4;
}

std::vector<int> RSAEncryptedBlock::GetRaw()
{
	return exportBuffer;
}
