#include "Crypto/Crypto.h"
#include "Crypto/Algorithms/Base/Structs/DecryptResult.h"
#include "Crypto/Validators/HeaderValidator/Structs/ValidationResult.h"
#include "Crypto/Algorithms/Shared/ZLib/Structs/zlibResult.h"


SLineageFileSchema Crypto::Decrypt(const std::shared_ptr<ReadableStream>& input, const std::shared_ptr<WritableStream>& output)
{
	SLineageFileSchema schema;
	schema.type = ECryptType::DEC;

	auto validator = StreamFactory::Make(HeaderValidatorDuplex(schema));
	auto algorithm = StreamFactory::Make(AlgorithmDuplex(schema));
	auto inflator = StreamFactory::Make(InflateDuplex(schema));

	// Log steps

	LogCurrentStep("Header validation", 0);
	validator->Bind_OnValidationPassed([&](const SValidationResult& res) {
		// Do stuff if header validation passed.
		std::cout << "Header validation passed, using:" << schema.header << std::endl;
	});

	validator->Bind_OnValidationFailed([&](const SValidationResult& res) {
		// Do stuff if header validation failed.
	});

	LogCurrentStep("Decrypt operation", 1);
	algorithm->Bind_OnDecryptPassed([&](const SDecryptResult& res) {
		 //Do stuff if when decrypt passed.
		//step++;
	});

	algorithm->Bind_OnDecryptFailed([&](const SDecryptResult& res) {
		// Do stuff if when decrypt failed.
	});

	LogCurrentStep("Inflate operation :", 2);
	inflator->Bind_OnInflatePassed([&](const SZlibResult& res) {
		// Do stuff if when inflate passed.
	});

	// Pipe the duplex streams.
	input
		->Pipe(validator)
		->Pipe(algorithm)
		->Pipe(inflator)
		->Pipe(output);

	input->Start();

	return schema;
}

SLineageFileSchema Crypto::Encrypt(const char* inBuffer)
{
	SLineageFileSchema schema;

	// TODO Not yet implemented.

	return schema;
}

void Crypto::LogCurrentStep(std::string title, short step)
{
	std::cout << "" << title << " | step [" << step << "/" << maxSteps << "]" << std::endl;
}
