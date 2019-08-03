#ifndef H_ALGORITHM
#define H_ALGORITHM

#include <memory>
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
	virtual ~Algorithm() = default;

	/**
	 * Get instance header version.
	 *
	 * @return EHeaderVersion header version
	 */
	EHeaderVersion GetVersion() const;

	/**
	 * Sets internal input buffer.
	 * @param const char* inBuffer buffer with source data.
	 * @return void
	 */
	void SetBuffer(const char* inBuffer);

	/**
	 * Gets duplex that are related to this algorithm.
	 * @return const DuplexTypes&
	 */
	const DuplexTypes& GetDuplex() const;

	/**
	 * Override & call this to reset/cleanup any unmanaged code.
	 */
	virtual void Reset();

protected:
	EHeaderVersion version = NOT_IMPL;
	DuplexTypes duplex;

	/**
	 * Gets the current buffer, for internal use only
	 */
	const char* GetBuffer() const;

private:
	const char* buffer = nullptr;
};

#endif // H_ALGORITHM
