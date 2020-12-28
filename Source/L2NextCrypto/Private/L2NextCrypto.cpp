#include <iostream>

#include "L2NextCrypto.h"

std::string L2NextCrypto::Decrypt(const std::stringstream& encrypted)
{
	InputStream input(encrypted);
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

	algorithm.Bind_OnDecryptChunk([&](SDecryptedChunk chunk) {
		if (this->OnDecryptChunkCallback) {
			OnDecryptChunkCallback(chunk);
		}
	});

	inflator.Bind_OnInflateChunk([&](SInflatedChunk chunk) {
		if (this->OnInflateChunkCallback) {
			OnInflateChunkCallback(chunk);
		}
	});

	inflator.Bind_OnInflateFailed([](const int& res) {
		throw EDecryptError::INFLATE_FAILED;
	});

	input >> validator >> algorithm >> inflator >> output;

	return output.GetResult();
}

void L2NextCrypto::OnDecryptChunk(std::function<void(const SDecryptedChunk&)> callback)
{
	OnDecryptChunkCallback = callback;
}

void L2NextCrypto::OnInflateChunk(std::function<void(const SInflatedChunk&)> callback)
{
	OnInflateChunkCallback = callback;
}
