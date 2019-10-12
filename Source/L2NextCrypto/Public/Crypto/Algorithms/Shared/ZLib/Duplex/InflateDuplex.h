#ifndef H_INFLATE_DUPLEX
#define H_INFLATE_DUPLEX

#include <memory>

#include "Shared/Structs/LineageFileSchema.h"
#include "Utils/Streams/DuplexStream.h"
#include "Crypto/Algorithms/Shared/ZLib/Events/InflatePassed.h"
#include "Crypto/Algorithms/Shared/ZLib/Events/InflateFailed.h"

using namespace::L2NextCryptoStreams;

class InflateDuplex 
	: public DuplexStream
	, public CryptoEvents::OnInflatePassed
	, public CryptoEvents::OnInflateFailed
{
public:

	InflateDuplex(SLineageFileSchema& schema)
		: schema(schema)
	{
		
	}

	std::shared_ptr<std::iostream> Transform(const std::shared_ptr<std::iostream>& stream) final;

private:
	SLineageFileSchema& schema;
};

#endif // H_INFLATE_DUPLEX