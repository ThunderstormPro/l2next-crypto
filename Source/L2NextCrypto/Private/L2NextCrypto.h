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
#include "Crypto/Validators/HeaderValidator/Duplex/HeaderValidatorDuplex.h"
#include "Crypto/Algorithms/Base/Duplex/AlgorithmDuplex.h"
#include "Crypto/Algorithms/Shared/ZLib/Duplex/InflateDuplex.h"
#include "Utils/Streams/InputStream.h"
#include "Utils/Streams/OutputStream.h"
#include "Utils/Streams/DuplexStream.h"
#include "Crypto/Enums/HeaderVersion.h"
#include "Crypto/Enums/CryptType.h"
#include "Crypto/Enums/DecryptError.h"
#include "Crypto/Enums/EncryptError.h"

class L2NextCrypto
{
public:
	std::string Decrypt(const std::stringstream& encrypted);

	void OnDecryptChunk(std::function<void(const SDecryptedChunk&)> callback);
	void OnInflateChunk(std::function<void(const SInflatedChunk&)> callback);

private:
	std::function<void(const SDecryptedChunk&)> OnDecryptChunkCallback;
	std::function<void(const SInflatedChunk&)> OnInflateChunkCallback;
};

#endif
