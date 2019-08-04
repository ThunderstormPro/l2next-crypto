#ifndef H_INFLATE_DUPLEX
#define H_INFLATE_DUPLEX

#include <memory>
#include <vector>
#include <iostream>
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


#endif // H_INFLATE_DUPLEX