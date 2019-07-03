#ifndef H_VER41XDEC
#define H_VER41XDEC

#include <string>
#include "Crypto/Algorithms/41x/Shared/Ver41xParams.h"
#include "Utils/Streams/Factory/StreamFactory.h"

using namespace::LineageCryptoStreams;

class Ver41xDec : public DuplexStream
{
public:
	Ver41xDec(Ver41xParams& params);
	~Ver41xDec();

public:
	virtual std::shared_ptr<std::iostream> Transform(const std::shared_ptr<std::iostream>& stream) final;

private:
	Ver41xParams params;
};

#endif // H_VER41XDEC
