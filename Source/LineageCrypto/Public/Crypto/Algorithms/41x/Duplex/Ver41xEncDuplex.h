#ifndef H_VER41XENC
#define H_VER41XENC

#include <string>
#include "Crypto/Algorithms/41x/Shared/Ver41xParams.h"

class Ver41xEnc
{
public:
	Ver41xEnc(Ver41xParams params);
	~Ver41xEnc();


	//void Transform(const char*& inBuffer, char*& outBuffer) override;
};

#endif // H_VER41XENC
