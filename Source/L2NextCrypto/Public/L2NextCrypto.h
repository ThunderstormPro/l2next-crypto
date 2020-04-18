#ifndef H_LINEAGE_CRYPTO
#define H_LINEAGE_CRYPTO

#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <ostream>
#include <fstream>
#include "Crypto/Validators/HeaderValidator/Duplex/HeaderValidatorDuplex.h"
#include "Crypto/Algorithms/Base/Duplex/AlgorithmDuplex.h"
#include "Crypto/Algorithms/Shared/ZLib/Duplex/InflateDuplex.h"
#include "Utils/Streams/InputStream.h"
#include "Utils/Streams/OutputStream.h"
#include "Utils/Streams/DuplexStream.h"
#include "Crypto/Enums/HeaderVersion.h"
#include "Crypto/Enums/CryptType.h"
#include "Crypto/Enums/DecryptErrorStatus.h"
#include "Crypto/Enums/EncryptErrorStatus.h"
#include "Crypto/Structs/DecryptResult.h"
#include "Crypto/Structs/EncryptResult.h"
#include "Shared/Structs/FileData.h"
#include <iostream>

using namespace L2NextCryptoStreams;

class L2NextCrypto
{
public:
	static SDecryptResult Decrypt(SFileData encrypted);
	static SEncryptResult Encrypt(SFileData decrypted);
};

#endif
