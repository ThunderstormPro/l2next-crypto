#include "Crypto/Algorithms/41x/Duplex/Ver41xDecDuplex.h"
#include "Crypto/Algorithms/Base/Duplex/AlgorithmDuplex.h"
#include "Crypto/Algorithms/Shared/Rsa/RsaEncryptedBlock.h"

Ver41xDecDuplex::Ver41xDecDuplex(Ver41xParams& params)
	: params(params)
{
}

std::stringstream& Ver41xDecDuplex::Transform(std::stringstream& input)
{
	RSAEncryptedBlock header(input, params.modulus, params.exponent, BLOCK_SIZE);
	int predefinedDecSize = reinterpret_cast<unsigned int*>(&(header.GetBuffer())[header.GetBlockStartPosition()])[0];

	if (predefinedDecSize <= 0)
	{
		return input;
	}

	current.write(&(header.GetBuffer())[(header.GetBlockStartPosition() + 4)], header.GetBlockSize() - 4);

	while (!input.eof())
	{
		RSAEncryptedBlock block(input, params.modulus, params.exponent, BLOCK_SIZE);

		if (block.GetBlockSize() > BLOCK_SIZE)
		{
			break;
		}

		current.write(&(block.GetBuffer())[block.GetBlockStartPosition()], block.GetBlockSize());
	}

	return current;
}