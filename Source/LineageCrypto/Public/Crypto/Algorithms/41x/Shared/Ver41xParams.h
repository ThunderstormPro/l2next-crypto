#ifndef H_VER41X_PARAMS
#define H_VER41X_PARAMS

#include <vector>

using namespace::std;

struct Ver41xParams
{
	std::vector<unsigned char> publicModulus;
	unsigned long privateExponent;

};

#endif // H_VER41X_PARAMS
