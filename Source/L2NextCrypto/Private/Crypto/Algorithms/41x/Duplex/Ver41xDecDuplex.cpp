#include "Crypto/Algorithms/41x/Duplex/Ver41xDecDuplex.h"
#include "Crypto/Algorithms/Base/Duplex/AlgorithmDuplex.h"
#include "Crypto/Algorithms/Shared/Rsa/RsaEncryptedBlock.h"

Ver41xDecDuplex::Ver41xDecDuplex(Ver41xParams& params)
	: params(params)
{
}

std::stringstream& Ver41xDecDuplex::Transform(std::stringstream& input)
{
	SAlgorithmResult result;
	RSAEncryptedBlock header(input, params.modulus, params.exponent, BLOCK_SIZE);
	decompressedSize = reinterpret_cast<unsigned int*>(&(header.GetBuffer())[header.GetBlockStartPosition()])[0];

	if (decompressedSize <= 0)
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

	//result.fileSize = decompressedSize;

	return current;
}
/*
std::shared_ptr<std::iostream> Ver41xDecDuplex::Transform(const std::shared_ptr<std::iostream>& stream)
{
	const auto decrypted = std::make_shared<std::stringstream>();

	RSAEncryptedBlock header(stream, params.modulus, params.exponent, BLOCK_SIZE);
	decompressedSize = reinterpret_cast<unsigned int*>(&(header.GetBuffer())[header.GetBlockStartPosition()])[0];

	result = std::make_shared<SDecryptResult>();

	if (decompressedSize <= 0)
	{
		result->errorCode = -1;
		result->msg = "Cannot get decompressed size. Aborting decrypting.";
		SetExecResult(result);

		return nullptr;
	}

	decrypted->write(&(header.GetBuffer())[(header.GetBlockStartPosition() + 4)], header.GetBlockSize() - 4);

	while (!stream->eof())
	{
		RSAEncryptedBlock block(stream, params.modulus, params.exponent, BLOCK_SIZE);

		if (block.GetBlockSize() > BLOCK_SIZE)
		{
			break;
		}

		decrypted->write(&(block.GetBuffer())[block.GetBlockStartPosition()], block.GetBlockSize());
	}

	result->errorCode = 0;
	result->fileSize = decompressedSize;
	SetExecResult(result);

	return decrypted;
}
*/