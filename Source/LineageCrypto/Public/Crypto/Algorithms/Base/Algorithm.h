#ifndef H_ALGORITHM
#define H_ALGORITHM

#include <memory>
#include <iostream>
#include "Crypto/Algorithms/Base/Duplex.h"
#include "Crypto/Enums/CryptType.h"
#include "Crypto/Enums/HeaderVersion.h"

using namespace::std;

struct DuplexTypes
{
	unique_ptr<Duplex> encrypt;
	unique_ptr<Duplex> decrypt;
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
	virtual EHeaderVersion GetVersion();

	/**
	 * Sets internal input buffer.
	 * @param const char* inBuffer buffer with source data.
	 * @return void
	 */
	virtual void SetBuffer(const char* inBuffer);

	/**
	 * Gets algorithm result.
	 * @param ECryptType type operation encrypt or decrypt.
	 * @param char*& outBuffer output buffer to write the results to.
	 * @return void
	 */
	virtual void GetResult(ECryptType type, char*& outBuffer);

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
