#ifndef H_VER41XDEC
#define H_VER41XDEC

#include "Crypto/Algorithms/41x/Shared/Ver41xParams.h"
#include "Utils/Streams/Factory/StreamFactory.h"
#include "Crypto/Algorithms/Base/Structs/DecryptResult.h"
#include "Utils/Streams/DuplexStream.h"

#define BLOCK_SIZE 128

using namespace::L2NextCryptoStreams;

class Ver41xDecDuplex 
	: public DuplexStream
{
public:
	Ver41xDecDuplex(Ver41xParams& params);
	~Ver41xDecDuplex() = default;

	std::shared_ptr<std::iostream> Transform(const std::shared_ptr<std::iostream>& stream) override final;
private:
	Ver41xParams params;
	int decompressedSize = 0;
	std::shared_ptr<SDecryptResult> result;
};

#endif // H_VER41XDEC
