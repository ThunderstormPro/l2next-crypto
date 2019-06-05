#ifndef H_VER41XDEC
#define H_VER41XDEC

#include <string>
#include "Crypto/Algorithms/41x/Shared/Ver41xParams.h"
#include "Crypto/Algorithms/Base/Duplex.h"

class Ver41xDec : public Duplex
{
public:
	Ver41xDec(Ver41xParams& params);
	~Ver41xDec();

public:
	void Transform(const char*& inBuffer, char*& outBuffer) override;

private:
	Ver41xParams params;
};

#endif // H_VER41XDEC
