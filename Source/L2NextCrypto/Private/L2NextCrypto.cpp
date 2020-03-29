#include "L2NextCrypto.h"

SDecryptResult L2NextCrypto::Decrypt(const char* encrypted, const int size)
{
	SDecryptResult result;

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
		}
		else if (res.version == NOT_IMPL) {
			throw EDecryptStatus::VERSION_NOT_SUPPORTED;
		}
		});

	input >> validator >> algorithm >> inflator >> output;

	result.content = SFileData(output.GetData());

	return result;
}

SEncryptResult L2NextCrypto::Encrypt(std::string decrypted)
{
	return SEncryptResult();
}