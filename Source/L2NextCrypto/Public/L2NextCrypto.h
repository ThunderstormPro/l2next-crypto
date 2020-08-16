#ifndef H_LINEAGE_CRYPTO
#define H_LINEAGE_CRYPTO

#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <ostream>
#include <fstream>
#include <iostream>
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

using namespace L2NextCryptoStreams;

class L2NextCrypto
{
public:
	static std::vector<unsigned char> Decrypt(const std::stringstream& encrypted);
	static std::vector<unsigned char> Decrypt(const std::vector<unsigned char>& encrypted);

private:
	static std::vector<unsigned char> Decrypt(InputStream& encrypted);
};

#endif
