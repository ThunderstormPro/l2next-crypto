#ifndef H_VER413
#define H_VER413

#include <string>
#include "Crypto/Enums/CryptType.h"
#include "Crypto/Enums/HeaderVersion.h"
#include "Crypto/Algorithms/Base/Algorithm.h"
#include "Crypto/Algorithms/41x/Shared/Ver41xParams.h"
#include "Crypto/Algorithms/41x/Duplex/Ver41xEncDuplex.h"
#include "Crypto/Algorithms/41x/Duplex/Ver41xDecDuplex.h"

using namespace::std;

class Ver413 : public Algorithm
{
public:
	Ver413()
	{
		Ver41xParams params;
		params.keys = 444;

		version = EHeaderVersion::VER_413;
		duplex = {
			StreamFactory::Make<Ver41xDec>(params),
			StreamFactory::Make<Ver41xDec>(params)
		};
	}
};

#endif // H_VER413
