#include "L2NextCrypto.h"

SDecryptResult L2NextCrypto::Decrypt(SFileData encrypted)
{
	SDecryptResult result;

	InputStream input(encrypted.GetData(), encrypted.GetSize());
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
			throw EDecryptErrorStatus::INVALID_HEADER;
		}
		else if (res.version == NOT_IMPL) {
			throw EDecryptErrorStatus::VERSION_NOT_SUPPORTED;
		}
		});

	inflator.Bind_OnInflateFailed([](const int& res) {
		throw EDecryptErrorStatus::INFLATE_FAILED;
		});

	input >> validator >> algorithm >> inflator >> output;

	result.content = SFileData(output.GetData());

	return result;
}

SEncryptResult L2NextCrypto::Encrypt(SFileData decrypted)
{
	return SEncryptResult();
}