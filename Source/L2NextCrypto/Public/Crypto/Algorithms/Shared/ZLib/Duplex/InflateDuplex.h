#ifndef H_INFLATE_DUPLEX
#define H_INFLATE_DUPLEX

#include <memory>

#include "Shared/Structs/LineageFileSchema.h"
#include "Utils/Streams/DuplexStream.h"
#include "Crypto/Algorithms/Shared/ZLib/Events/InflatePassed.h"
#include "Crypto/Algorithms/Shared/ZLib/Events/InflateFailed.h"

#define CHUNK 16384

using namespace::L2NextCryptoStreams;

class InflateDuplex: public DuplexStream
{
public:
	std::stringstream& Transform(std::stringstream& input);
};

#endif // H_INFLATE_DUPLEX