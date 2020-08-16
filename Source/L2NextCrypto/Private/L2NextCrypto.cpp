#include "L2NextCrypto.h"

std::vector<unsigned char> L2NextCrypto::Decrypt(const std::vector<unsigned char>& encrypted)
{
	std::stringstream stream;

	std::copy(encrypted.begin(), encrypted.end(), std::ostream_iterator<unsigned char>(stream));

	InputStream input(stream);

	return L2NextCrypto::Decrypt(input);
}


std::vector<unsigned char> L2NextCrypto::Decrypt(const std::stringstream& encrypted)
{
	InputStream input(encrypted);

	return L2NextCrypto::Decrypt(input);
}


std::vector<unsigned char> L2NextCrypto::Decrypt(InputStream& encrypted)
{
	HeaderValidatorDuplex validator;
	AlgorithmDuplex algorithm(ECryptType::DEC);
	InflateDuplex inflator;
	OutputStream output;

	validator.Bind_OnValidationPassed([&](const SValidationResult& res) {
		algorithm.SetVersion(res.version);
	});

	validator.Bind_OnValidationFailed([&](const SValidationResult& res) {
		if (res.version == INVALID) {
			throw EDecryptError::INVALID_HEADER;
		}
		else if (res.version == NOT_IMPL) {
			throw EDecryptError::VERSION_NOT_SUPPORTED;
		}
	});

	inflator.Bind_OnInflateFailed([](const int& res) {
		throw EDecryptError::INFLATE_FAILED;
	});

	encrypted >> validator >> algorithm >> inflator >> output;

	return output.GetBuffer();
}
