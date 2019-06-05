#ifndef H_DUPLEX
#define H_DUPLEX

#include <memory>
#include "Crypto/Enums/CryptType.h"
#include "Crypto/Enums/HeaderVersion.h"

using namespace::std;

class Duplex
{
public:
	template<class T, class C>
	static unique_ptr<Duplex> Construct(C& params) {
		return make_unique<T>(params);
	}

	virtual void Transform(const char*& inBuffer, char*& outBuffer) {};

protected:
	char* container;
};

#endif // H_DUPLEX
