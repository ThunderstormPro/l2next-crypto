#ifndef H_VER41XDEC
#define H_VER41XDEC

#include <algorithm>
#include "gmp.h"
#include <cassert>
#include <vector>
#include "zlib.h"
#include "Crypto/Algorithms/41x/Shared/Ver41xParams.h"
#include "Utils/Streams/Factory/StreamFactory.h"

#define BLOCK_SIZE 128

constexpr int ReverseBytes(int value)
{
	char* bytes = (char*)&value;
	return (int)bytes[3] | ((int)bytes[2] << 8) | ((int)bytes[1] << 16) | ((int)bytes[0] << 24);
}

class RSABlock
{
public:
	RSABlock(const std::shared_ptr<std::iostream>& stream, size_t bufferSize)
		: stream(stream)
		, bufferSize(bufferSize)
	{
		 
	};

	virtual char* GetBuffer() = 0;
	virtual size_t GetBlockSize() = 0;
	virtual size_t GetBufferSize() = 0;
	virtual std::vector<int> GetRaw() = 0;

protected:
	std::vector<char> importBuffer;
	std::vector<int> exportBuffer;
	const std::shared_ptr<std::iostream>& stream;
	mpz_t modulus, readBlock, modPowedBlock;
	std::size_t count = 32;
	std::size_t bufferSize;
};

class RSAEncryptedBlock : public RSABlock
{
public:
	RSAEncryptedBlock(const std::shared_ptr<std::iostream>& stream, std::vector<unsigned char> mod, unsigned long exp, size_t bufferSize)
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

		count = 32;
		//memset(exportBuffer.data(), 0, 128);
		exportBuffer.resize(128);

		mpz_export(exportBuffer.data(), &count, 1, sizeof(int), 1, 0, modPowedBlock);
	}

	~RSAEncryptedBlock()
	{
		mpz_clear(modulus);
		mpz_clear(readBlock);
		mpz_clear(modPowedBlock);
	}

	size_t GetBlockSize()
	{
		return ReverseBytes(exportBuffer.at(0)); //((char*)exportBuffer.data())[3] & 0xff;
	}

	virtual size_t GetBufferSize() final
	{
		if ((size_t)stream->gcount() == exportBuffer.size())
		{
			return exportBuffer.size();
		}

		return stream->gcount();
	}

	virtual char* GetBuffer() final
	{
		return (char*)exportBuffer.data();
	}

	size_t GetBlockStartPosition()
	{
		return bufferSize - GetBlockSize() - ((124 - GetBlockSize()) % 4);
	}

	virtual std::vector<int> GetRaw() final
	{
		return exportBuffer;
	}
};

using namespace::LineageCryptoStreams;

class Ver41xDecDuplex : public DuplexStream
{
public:
	Ver41xDecDuplex(Ver41xParams& params);
	~Ver41xDecDuplex();

	/**
	 * Returns a new stream from new stream or an empty string when failed.
	 */
	virtual std::shared_ptr<std::iostream> Transform(const std::shared_ptr<std::iostream>& stream) final;

	void SetExecResult(const SStreamExecResult& err) override;
	SStreamExecResult GetExecResult() override;

private:
	Ver41xParams params;
	int decompressedSize = 0;

	SStreamExecResult result;
};

#endif // H_VER41XDEC
