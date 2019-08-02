#include "Crypto/Algorithms/41x/Duplex/Ver41xDecDuplex.h"

Ver41xDecDuplex::Ver41xDecDuplex(Ver41xParams& params)
	: params(params)
{
}

Ver41xDecDuplex::~Ver41xDecDuplex()
{

}

std::shared_ptr<std::iostream> Ver41xDecDuplex::Transform(const std::shared_ptr<std::iostream>& stream)
{
	const auto decrypted = std::make_shared<std::stringstream>();
	
	RSAEncryptedBlock header(stream, params.modulus, params.exponent, BLOCK_SIZE);
	decompressedSize = ((unsigned int *)&(header.GetBuffer())[header.GetBlockStartPosition()])[0];

	if (decompressedSize <= 0)
	{
		Stop();
		return stream;
	}

	decrypted->write(&(header.GetBuffer())[(header.GetBlockStartPosition())], header.GetBlockSize());

	while (!stream->eof())
	{
		RSAEncryptedBlock block(stream, params.modulus, params.exponent, BLOCK_SIZE);

		if (block.GetBlockSize() > BLOCK_SIZE)
		{
			break;
		}

		decrypted->write(&(block.GetBuffer())[block.GetBlockStartPosition()], block.GetBlockSize());
	}

	// Set values to schema, for the next stream.


	return decrypted;
}