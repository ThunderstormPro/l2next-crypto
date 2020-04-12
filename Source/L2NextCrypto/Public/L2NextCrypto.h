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
#include <iostream>

using namespace L2NextCryptoStreams;
using namespace::std;

enum class EDecryptErrorStatus
{
	VERSION_NOT_SUPPORTED,
	INVALID_HEADER,
	INFLATE_FAILED,
	NONE
};

enum class EEncryptErrorStatus
{
	VERSION_NOT_SUPPORTED,
	INVALID_HEADER,
	DEFLATE_FAILED,
	NONE
};

struct SFileData {
	SFileData()
		: contents("") {}

	void operator = (const SFileData& fd) {
		contents = fd.contents;
	};

	SFileData(const std::string contents) 
		: contents(contents) {}

	const char* GetData() {
		return contents.c_str();
	}

	const size_t GetSize() {
		return contents.size();
	}

private:
	std::string contents;
};

struct SDecryptResult
{
	int version;
	SFileData content;
};

struct SEncryptResult
{
	int version;
	SFileData content;
};

class L2NextCryptoUtils
{
public:
	static SFileData ReadFromFile(std::string filepath) {
		std::ifstream file(filepath, std::ios::in | std::ios::binary);

		if (file)
		{
			std::string contents;
			file.seekg(0, std::ios::end);
			contents.resize(file.tellg());
			file.seekg(0, std::ios::beg);
			file.read(&contents[0], contents.size());
			file.close();
			return SFileData(contents);
		}
		throw(errno);

		return SFileData("");
	}

	static bool WriteToFile(std::string filepath, SDecryptResult decryptedResult) {

		std::ofstream file(filepath, std::ios::out | std::ios::binary);

		if (file)
		{
			SFileData content = decryptedResult.content;

			file.write(content.GetData(), content.GetSize());
			file.close();

			return true;
		}
		throw(errno);

		return true;
	}
};

class L2NextCrypto
{
public:
	static SDecryptResult Decrypt(SFileData encrypted);
	static SEncryptResult Encrypt(SFileData decrypted);
};

#endif
