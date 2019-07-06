#ifndef H_ALGORITHM
#define H_ALGORITHM

#include <memory>
#include <iostream>
#include "Crypto/Enums/CryptType.h"
#include "Crypto/Enums/HeaderVersion.h"
#include "Utils/Streams/Factory/StreamFactory.h"

using namespace::LineageCryptoStreams;

struct DuplexTypes
{
	std::shared_ptr<DuplexStream> encrypt;
	std::shared_ptr<DuplexStream> decrypt;
};

class Algorithm
{
public:
	~Algorithm() {};

	/**
	 * Get instance header version.
	 *
	 * @return EHeaderVersion header version
	 */
	EHeaderVersion GetVersion();

	/**
	 * Sets internal input buffer.
	 * @param const char* inBuffer buffer with source data.
	 * @return void
	 */
	void SetBuffer(const char* inBuffer);

	/**
	 * Gets algorithm result.
	 * @param ECryptType type operation encrypt or decrypt.
	 * @param char*& outBuffer output buffer to write the results to.
	 * @return void
	 */
	void GetResult(ECryptType type, char*& outBuffer);

	const DuplexTypes& GetDuplex()
	{
		return duplex;
	}

	/**
	 * Override & call this to reset/cleanup any unmanaged code.
	 */
	virtual void Reset();

protected:
	EHeaderVersion version = EHeaderVersion::NOT_IMPL;
	DuplexTypes duplex;

	/**
	 * Gets the current buffer, for internal use only
	 */
	const char* GetBuffer() const;

private:
	const char* buffer = nullptr;
};

#endif // H_ALGORITHM
