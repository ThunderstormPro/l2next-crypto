#ifndef H_RSA_ENCRYPTED_BLOCK
#define H_RSA_ENCRYPTED_BLOCK

#include <memory>
#include <vector>
#include "RsaBlock.h"


class RSAEncryptedBlock : public RSABlock
{
public:
	RSAEncryptedBlock(const std::shared_ptr<std::iostream>& stream, std::vector<unsigned char> mod, unsigned long exp, size_t bufferSize);

	~RSAEncryptedBlock();

	size_t GetBlockStartPosition();

	size_t GetBlockSize() override final;

	size_t GetBufferSize() override final;

	char* GetBuffer() override final;

	std::vector<int> GetRaw() override final;
};


#endif // H_RSA_ENCRYPTED_BLOCK
