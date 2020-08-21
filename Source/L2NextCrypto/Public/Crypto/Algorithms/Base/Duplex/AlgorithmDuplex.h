#ifndef H_ALGORITHM_DUPLEX
#define H_ALGORITHM_DUPLEX

#include <memory>
#include <sstream>
#include "Utils/Streams/DuplexStream.h"
#include "Crypto/Enums/CryptType.h"
#include "Crypto/Algorithms/Base/Events/OnDecryptChunk.h"
#include "Crypto/Algorithms/Base/Events/OnDecryptFailed.h"

using namespace::L2NextCryptoStreams;
using namespace::CryptoEvents;

class AlgorithmDuplex
	: public DuplexStream
	, public OnDecryptChunk
	, public OnDecryptFailed
{
public:

	AlgorithmDuplex(ECryptType type)
		: type(type)
		, version(0)
	{}

	void SetVersion(const int ver);

protected:
	std::stringstream& Transform(std::stringstream& stream) override final;

private:
	int version;
	ECryptType type;
};

#endif // H_ALGORITHM_DUPLEX
