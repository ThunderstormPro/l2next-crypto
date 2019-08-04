#ifndef H_ALGORITHM_DUPLEX
#define H_ALGORITHM_DUPLEX

#include <memory>
#include "Utils/Streams/Factory/StreamFactory.h"
#include "Shared/Structs/LineageFileSchema.h"
#include "Crypto/Algorithms/Base/Events/OnDecryptPassed.h"
#include "Crypto/Algorithms/Base/Events/OnDecryptFailed.h"

using namespace::LineageCryptoStreams;

class AlgorithmDuplex
	: public DuplexStream
	, public CryptoEvents::OnDecryptPassed
	, public CryptoEvents::OnDecryptFailed
{
public:
	AlgorithmDuplex(SLineageFileSchema& schema)
		: schema(schema)
	{
		
	}
private:
	SLineageFileSchema& schema;
	std::shared_ptr<std::iostream> Transform(const std::shared_ptr<std::iostream>& stream) override;
};

#endif // H_ALGORITHM_DUPLEX
