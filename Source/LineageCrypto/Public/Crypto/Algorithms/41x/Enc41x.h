#ifndef H_ENC41X
#define H_ENC41X

#include "Crypto/Algorithms/Base/AlgorithmBase.h"

using namespace::std;

class Enc41x: public AlgorithmBase
{
public:
	/** Methods */
	virtual void SetInputData(const char* buffer) override;
	virtual void GetExecResult(char*& result) override;
	virtual void Reset() override;
};

#endif // H_ENC41X
