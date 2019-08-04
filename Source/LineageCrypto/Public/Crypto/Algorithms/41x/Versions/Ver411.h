#ifndef H_VER411
#define H_VER411

#include "Crypto/Algorithms/Base/Algorithm.h"
#include "Crypto/Algorithms/41x/Shared/Ver41xParams.h"

using namespace::std;

class Ver411 : public Algorithm, public Ver41xParams
{
public:
	Ver411()
	{
		version = VER_411;
	}
};

#endif // H_VER411
