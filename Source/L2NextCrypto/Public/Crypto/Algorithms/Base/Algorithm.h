#ifndef H_ALGORITHM
#define H_ALGORITHM

#include <memory>
#include "Utils/Streams/DuplexStream.h"
#include "Crypto/Enums/HeaderVersion.h"

using namespace::L2NextCryptoStreams;

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
	 * Gets duplex that are related to this algorithm.
	 * @return const DuplexTypes&
	 */
	const DuplexTypes& GetDuplex() const;

protected:
	EHeaderVersion version = NOT_IMPL;
	DuplexTypes duplex;
};

#endif // H_ALGORITHM
