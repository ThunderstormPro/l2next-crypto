#ifndef H_VER412
#define H_VER412

#include "Crypto/Enums/CryptType.h"
#include "Crypto/Enums/HeaderVersion.h"
#include "Crypto/Algorithms/Base/Algorithm.h"
#include "Crypto/Algorithms/41x/Shared/Ver41xParams.h"
#include "Crypto/Algorithms/41x/Duplex/Ver41xEnc.h"
#include "Crypto/Algorithms/41x/Duplex/Ver41xDec.h"

using namespace::std;

class Ver412 : public Algorithm, public Ver41xParams
{
public:
	Ver412()
	{
		version = EHeaderVersion::VER_412;
		//duplex = {
		//	Duplex::Construct<Ver41xEnc>(this),
		//	Duplex::Construct<Ver41xDec>(this)
		//};
	}
};

#endif // H_VER412
