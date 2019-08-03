#ifndef H_CRYPTO
#define H_CRYPTO

#include <string>
#include <memory>
#include <regex>
#include <vector>
#include <algorithm>
#include "Enums/CryptType.h"
#include "Shared/Structs/LineageFileSchema.h"
#include "Algorithms/AlgorithmRegistry.h"
#include "Algorithms/Base/Algorithm.h"
#include "Crypto/Algorithms/Base/Duplex/AlgorithmDuplex.h"
#include "Algorithms/Shared/InflateDuplex.h"
#include "Algorithms/Shared/DeflateDuplex.h"
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

private:
	/**
	 * Checks if buffer contains a valid Lineage2Ver header.
	 *
	 * @param SLineageFileSchema& a reference to the current schema result.
	 * @param char*& buffer a reference to input char buffer.
	 * @return bool is a valid header or not.
	 */
	//static bool ValidateHeader(SLineageFileSchema& schema, const char*& buffer);

	/**
	 * Perform encrypt/decrypt operation with appropriate algorithm on buffer.
	 *
	 * @param SLineageFileSchema& a reference to the current schema result.
	 * @param char*& buffer a reference to input char buffer.
	 * @return bool operation status.
	 */
	//static bool SetCryptResultToBuffer(SLineageFileSchema& schema, const char*& buffer);
};

#endif // H_CRYPTO
