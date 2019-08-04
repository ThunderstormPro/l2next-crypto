#ifndef H_VER414
#define H_VER414

#include "Crypto/Enums/HeaderVersion.h"
#include "Crypto/Algorithms/Base/Algorithm.h"
#include "Crypto/Algorithms/41x/Shared/Ver41xParams.h"

using namespace::std;

class Ver414 : public Algorithm, public Ver41xParams
{
public:
	Ver414()
	{
		version = VER_414;
	}
};

#endif // H_VER414
