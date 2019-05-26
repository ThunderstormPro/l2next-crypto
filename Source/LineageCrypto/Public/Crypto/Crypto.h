#ifndef H_CRYPTO
#define H_CRYPTO

#include <string>
#include <memory>
#include "Shared/Structs/LineageFileSchema.h"
#include "Crypto/Algorithms/Base/AlgorithmBase.h"
#include "Crypto/Algorithms/41x/Enc41x.h"
#include "Crypto/Algorithms/41x/Dec41x.h"

using namespace::std;

enum ECryptType
{
	ENC,
	DEC
};


class Crypto
{
public:
	static SLineageFileSchema Decrypt(char* buffer);
	static SLineageFileSchema Encrypt(char* buffer);

private:
	static string GetHeader(char* buffer);
	static short GetHeaderVersion(string& header);
	static unique_ptr<AlgorithmBase> GetAlgorithm(ECryptType type, short& version);

	// Generic templates.
	template <class T>
	static unique_ptr<AlgorithmBase>  GetAlgorithmWithClass() {
		return make_unique<T>();
	}
};

#endif // H_CRYPTO
