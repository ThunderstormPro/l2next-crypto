#ifndef H_VER411
#define H_VER411

#include "Crypto/Enums/CryptType.h"
#include "Crypto/Enums/HeaderVersion.h"
#include "Crypto/Algorithms/Base/Algorithm.h"
#include "Crypto/Algorithms/41x/Shared/Ver41xParams.h"
#include "Crypto/Algorithms/41x/Duplex/Ver41xEncDuplex.h"
#include "Crypto/Algorithms/41x/Duplex/Ver41xDecDuplex.h"

using namespace::std;

class Ver411 : public Algorithm, public Ver41xParams
{
public:
	Ver411()
	{
		version = EHeaderVersion::VER_411;
		//duplex = {
		//	Duplex::Construct<Ver41xEnc>(this),
		//	Duplex::Construct<Ver41xDec>(this)
		//};
	}
};

#endif // H_VER411
