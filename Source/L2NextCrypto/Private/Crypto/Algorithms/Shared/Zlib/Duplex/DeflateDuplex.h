#ifndef H_DEFLATE_DUPLEX
#define H_DEFLATE_DUPLEX

#include <memory>
#include "Utils/Streams/DuplexStream.h"

using namespace::L2NextCryptoStreams;

class DeflateDuplex : public DuplexStream
{
public:
	std::stringstream& Transform(std::stringstream& input);
	
};

#endif // H_DEFLATE_DUPLEX
