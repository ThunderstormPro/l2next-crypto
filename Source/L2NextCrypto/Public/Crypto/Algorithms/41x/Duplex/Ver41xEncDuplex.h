#ifndef H_VER41XENC
#define H_VER41XENC

#include "Crypto/Algorithms/41x/Shared/Ver41xParams.h"
#include "Utils/Streams/DuplexStream.h"

class Ver41xEncDuplex
	: public L2NextCryptoStreams::DuplexStream
{
public:
	Ver41xEncDuplex(Ver41xParams& params);
	~Ver41xEncDuplex();
private:
	Ver41xParams params;

};

#endif // H_VER41XENC
