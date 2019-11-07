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

enum class EDecryptStatus
{
	SUCCESS,
	INVALID_HEADER,
	OPERATION_FAILED,
	VERSION_NOT_SUPPORTED,
	NONE
};

enum class EEncryptStatus
{
	SUCCESS,
	INVALID_FILE,
	OPERATION_FAILED,
	NONE
};

struct SFileData {
	std::string contents;

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
};

struct SDecryptResult 
{
	int version;
	SFileData content;
};

struct SEncryptResult
{
	EEncryptStatus status;
	std::string data;

	SEncryptResult()
		: data("")
		, status(EEncryptStatus::NONE) {}
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

	static bool WriteToFile(std::string filepath, const char* data, const int size) {

		std::ofstream file(filepath, std::ios::out | std::ios::binary);

		if (file)
		{
			file.write(data, size);
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
	static SDecryptResult Decrypt(const char* encrypted, const int size)
	{
		SDecryptResult result;

		// Streams.
		InputStream input(encrypted, size);
		HeaderValidatorDuplex validator;
		AlgorithmDuplex algorithm(ECryptType::DEC);
		InflateDuplex inflator;
		OutputStream output;

		validator.Bind_OnValidationPassed([&](const SValidationResult& res) {
			result.version = res.version;
			algorithm.SetVersion(res.version);
		});

		validator.Bind_OnValidationFailed([&](const SValidationResult& res) {
			if (res.version == INVALID) {
				throw EDecryptStatus::INVALID_HEADER;
			} else if (res.version == NOT_IMPL) {
				throw EDecryptStatus::VERSION_NOT_SUPPORTED;
			}
		});

		input >> validator >> algorithm >> inflator >> output;

		result.content = SFileData(output.GetData());

		return result;
	}

	static SEncryptResult Encrypt(std::string decrypted)
	{
		return SEncryptResult();
	}
};

#endif
