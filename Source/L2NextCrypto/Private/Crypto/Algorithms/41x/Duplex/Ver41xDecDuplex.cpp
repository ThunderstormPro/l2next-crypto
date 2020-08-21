#include "Crypto/Algorithms/41x/Duplex/Ver41xDecDuplex.h"
#include "Crypto/Algorithms/Base/Duplex/AlgorithmDuplex.h"
#include "Crypto/Algorithms/Shared/Rsa/RsaEncryptedBlock.h"
#include <iostream>


Ver41xDecDuplex::Ver41xDecDuplex(Ver41xParams& params)
	: params(params)
{
}

std::stringstream& Ver41xDecDuplex::Transform(std::stringstream& input)
{
	STransformedChunk transformedChunk;
	input.seekg(0, std::ios::end);
	transformedChunk.total = input.tellg();
	input.seekg(0, std::ios::beg);

	RSAEncryptedBlock header(input, params.modulus, params.exponent, BLOCK_SIZE);
	int predefinedDecSize = reinterpret_cast<unsigned int*>(&(header.GetBuffer())[header.GetBlockStartPosition()])[0];

	if (predefinedDecSize <= 0)
	{
		return input;
	}

	transformedChunk.current += header.GetBufferSize();

	current.write(&(header.GetBuffer())[(header.GetBlockStartPosition() + 4)], header.GetBlockSize() - 4);

	while (!input.eof())
	{
		RSAEncryptedBlock block(input, params.modulus, params.exponent, BLOCK_SIZE);

		transformedChunk.current += block.GetBufferSize();
		Exec_OnTransformChunk(transformedChunk);

		if (block.GetBlockSize() > BLOCK_SIZE)
		{
			break;
		}

		current.write(&(block.GetBuffer())[block.GetBlockStartPosition()], block.GetBlockSize());
	}

	return current;
}