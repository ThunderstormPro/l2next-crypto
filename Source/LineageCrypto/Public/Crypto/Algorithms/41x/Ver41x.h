#ifndef H_VER41X
#define H_VER41X

#include "Crypto/Algorithms/41x/Ver41xEnc.h"
#include "Crypto/Algorithms/41x/Ver41xDec.h"
#include "Crypto/Enums/CryptType.h"
#include "Crypto/Enums/HeaderVersion.h"
#include "Crypto/Algorithms/Base/AlgorithmBase.h"

using namespace::std;

class Ver41x : public AlgorithmBase
{
public:
	virtual EHeaderVersion GetVersion() override
	{
		return EHeaderVersion::VER_413;
	}

	virtual void GetResult(ECryptType type, char*& outBuffer) override
	{
		const char* inBuffer = GetBuffer();

		return type == ECryptType::ENC
			? Ver41xEnc(inBuffer).Process(outBuffer)
			: Ver41xDec(inBuffer).Process(outBuffer);
	}

	void Reset()
	{
		AlgorithmBase::Reset();
	}
};

#endif // H_VER41X
