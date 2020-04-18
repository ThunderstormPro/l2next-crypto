#ifndef H_INFLATE_DUPLEX
#define H_INFLATE_DUPLEX

#include <memory>

#include "Utils/Streams/DuplexStream.h"
#include "Crypto/Algorithms/Shared/ZLib/Events/OnInflateFailed.h"

constexpr unsigned int CHUNK = 16384;

using namespace::L2NextCryptoStreams;
using namespace::CryptoEvents;

class InflateDuplex
	: public DuplexStream
	, public OnInflateFailed
{
public:
	std::stringstream& Transform(std::stringstream& input);

private:
	std::vector<char> in = std::vector<char>(CHUNK);
	std::vector<char> out = std::vector<char>(CHUNK);
};

#endif // H_INFLATE_DUPLEX