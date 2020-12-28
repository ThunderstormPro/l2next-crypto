#ifndef H_L2NEXTCRYPTO
#define H_L2NEXTCRYPTO

#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <ostream>
#include <fstream>
#include <iostream>
#include <functional>

namespace CryptoEvents {
	struct SDecryptedChunk {
		unsigned int current;
		unsigned int total;
	};

	struct SInflatedChunk {
		unsigned int current;
		unsigned int total;
	};
}

enum class EDecryptError
{
	VERSION_NOT_SUPPORTED,
	INVALID_HEADER,
	INFLATE_FAILED,
	NONE
};

class L2NextCrypto
{
public:
	std::string Decrypt(const std::stringstream& encrypted);

	void OnDecryptChunk(std::function<void(const CryptoEvents::SDecryptedChunk&)> callback);
	void OnInflateChunk(std::function<void(const CryptoEvents::SInflatedChunk&)> callback);

private:
	std::function<void(const CryptoEvents::SDecryptedChunk&)> OnDecryptChunkCallback;
	std::function<void(const CryptoEvents::SInflatedChunk&)> OnInflateChunkCallback;
};

#endif
