#ifndef H_ALGORITHM_BASE
#define H_ALGORITHM_BASE

#include <memory>
#include "Crypto/Enums/CryptType.h"
#include "Crypto/Enums/HeaderVersion.h"

using namespace::std;

class AlgorithmBase
{
public:
	~AlgorithmBase() {};

	virtual EHeaderVersion GetVersion();
	virtual void SetBuffer(const char* buffer);
	virtual void GetResult(ECryptType type, char*& result) {};
	virtual void Reset();

protected:
	const char* GetBuffer() const;

private:
	const char* _buffer = nullptr;
};

#endif // H_ALGORITHM_BASE
