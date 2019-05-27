#ifndef H_CRYPTO
#define H_CRYPTO

#include <string>
#include <memory>
#include <regex>
#include <algorithm>
#include "Shared/Structs/LineageFileSchema.h"
#include "Crypto/Algorithms/Base/AlgorithmBase.h"
#include "Crypto/Algorithms/41x/Enc41x.h"
#include "Crypto/Algorithms/41x/Dec41x.h"

using namespace::std;

constexpr char NULL_TERMINATOR_CHR = '\0';
const string INVALID_HEADER = "INVALID_HEADER";
const regex LINEAGE_HEADER_SIGNATURE = regex("^Lineage2Ver\\d{3}$");
constexpr unsigned char LINEAGE_HEADER_SIZE = 28;
constexpr unsigned char LINEAGE_VERSION_LENGTH = 3;

enum class ECryptType
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
	static string GetHeaderString(char* buffer);
	static int GetHeaderVersion(string header);
	static unique_ptr<AlgorithmBase> GetAlgorithm(ECryptType type, short& version);

	// Generic templates.
	template <class T>
	static unique_ptr<AlgorithmBase>  GetAlgorithmWithClass() {
		return make_unique<T>();
	}
};

#endif // H_CRYPTO
