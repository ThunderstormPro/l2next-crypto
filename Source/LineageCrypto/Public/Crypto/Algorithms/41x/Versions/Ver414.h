#ifndef H_VER414
#define H_VER414

#include "Crypto/Enums/CryptType.h"
#include "Crypto/Enums/HeaderVersion.h"
#include "Crypto/Algorithms/Base/Algorithm.h"
#include "Crypto/Algorithms/41x/Shared/Ver41xParams.h"
#include "Crypto/Algorithms/41x/Duplex/Ver41xEncDuplex.h"
#include "Crypto/Algorithms/41x/Duplex/Ver41xDecDuplex.h"

using namespace::std;

class Ver414 : public Algorithm, public Ver41xParams
{
public:
	Ver414()
	{
		keys = 2;

		version = EHeaderVersion::VER_414;
		//duplex = {
		//	Duplex::Construct<Ver41xEnc>(this),
		//	Duplex::Construct<Ver41xDec>(this)
		//};
	}
};

#endif // H_VER414
