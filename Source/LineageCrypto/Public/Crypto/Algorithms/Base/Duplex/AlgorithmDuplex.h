#ifndef H_ALGORITHM_DUPLEX
#define H_ALGORITHM_DUPLEX

#include <memory>
#include "Crypto/Algorithms/AlgorithmRegistry.h"
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
	void SetFileSchema(const SLineageFileSchema& schema);



private:
	SLineageFileSchema schema = SLineageFileSchema();
	std::shared_ptr<std::iostream> Transform(const std::shared_ptr<std::iostream>& stream) override;
};

#endif // H_ALGORITHM_DUPLEX
