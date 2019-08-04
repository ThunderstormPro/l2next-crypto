#ifndef H_CRYPTO
#define H_CRYPTO

#include <string>
#include <memory>
#include <regex>
#include <vector>
#include <string>
#include <algorithm>
#include "Enums/CryptType.h"
#include "Shared/Structs/LineageFileSchema.h"
#include "Algorithms/AlgorithmRegistry.h"
#include "Algorithms/Base/Algorithm.h"
#include "Crypto/Algorithms/Base/Duplex/AlgorithmDuplex.h"
#include "Algorithms/Shared/ZLib/Duplex/InflateDuplex.h"
#include "Algorithms/Shared/ZLib/Duplex/DeflateDuplex.h"
#include "Validators/HeaderValidator/Duplex/HeaderValidatorDuplex.h"
#include "Utils/Streams/Factory/StreamFactory.h"

using namespace::std;

class Crypto
{
public:
	/**
	 * Decrypt a buffer containing Lineage2File data.
	 *
	 * @param char* character buffer read from L2 files.
	 * @return SLineageFileSchema the result of the decryption.
	 */
	static SLineageFileSchema Decrypt(const std::shared_ptr<ReadableStream>& input, const std::shared_ptr<WritableStream>& output);

	/**
	 * Encrypt a buffer as a Lineage2File data.
	 *
	 * @param char* character buffer read from decrypted files.
	 * @return SLineageFileSchema the result of the encryption.
	 */
	static SLineageFileSchema Encrypt(const char* buffer);
protected:
	static const short maxSteps = 4;
	static void LogCurrentStep(std::string title, short step);
};

#endif // H_CRYPTO
