#ifndef H_RSA_BLOCK
#define H_RSA_BLOCK

#include <memory>
#include <vector>
#include <sstream>
#include "Libs/mini-gmp.h"


class RSABlock
{
public:
	virtual ~RSABlock() = default;

	RSABlock(std::stringstream& stream, size_t bufferSize);;

	virtual char* GetBuffer() = 0;
	virtual size_t GetBlockSize() = 0;
	virtual size_t GetBufferSize() = 0;
	virtual std::vector<int> GetRaw() = 0;

protected:
	std::vector<char> importBuffer;
	std::vector<int> exportBuffer;
	std::stringstream& stream;
	mpz_t modulus, readBlock, modPowedBlock;
	std::size_t count = 32;
	std::size_t bufferSize;
};

#endif // H_RSA_BLOCK