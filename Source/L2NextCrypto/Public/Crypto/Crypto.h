#ifndef H_CRYPTO
#define H_CRYPTO

#include <memory>
#include "Shared/Structs/LineageFileSchema.h"
#include "Utils/Streams/Factory/StreamFactory.h"

using namespace::std;

class Crypto
{
public:
	/**
	 * Decrypt a buffer containing Lineage2File data.
	 *
	 * @param input readable stream.
	 * @param output writable stream.
	 * @return SLineageFileSchema the result of the decryption.
	 */
	static SLineageFileSchema Decrypt(const std::shared_ptr<L2NextCryptoStreams::ReadableStream>& input,
									  const std::shared_ptr<L2NextCryptoStreams::WritableStream>& output);

	/**
	 * TODO Make this function the same as decrypt.
	 * Encrypt a buffer as a Lineage2File data.
	 *
	 * @param char* character buffer read from decrypted files.
	 * @return SLineageFileSchema the result of the encryption.
	 */
	static SLineageFileSchema Encrypt(const char* buffer);
};

#endif // H_CRYPTO
