#include "Crypto/Crypto.h"



SLineageFileSchema Crypto::Decrypt(const std::shared_ptr<ReadableStream>& input, const std::shared_ptr<WritableStream>& output)
{
	SLineageFileSchema schema;

	auto validator = StreamFactory::Make(HeaderValidatorDuplex());
	auto algorithm = StreamFactory::Make(AlgorithmDuplex());
	auto inflator = StreamFactory::Make(InflateDuplex());

	schema.type = ECryptType::DEC;

	input
		->Pipe(validator)
		->Pipe(algorithm)
		->Pipe(inflator)
		->Pipe(output);

	input->Start();




	/*
	//auto input = StreamFactory::Make(ReadableStream(options));
	//auto output = StreamFactory::Make(WritableStream(options));
	/*
	
	input
		->Pipe(StreamFactory::Make(Custom41xStream()))
		->Pipe(output);

	input->Bind_OnEnd([&](double duration) {
		printf("Time taken: %.2fs\n", duration);
	});

	input->Start(); 
	
if (!ValidateHeader(schema, inBuffer))
	{
		return schema;
	}

	if (!SetCryptResultToBuffer(schema, inBuffer))
	{
		return schema;
	}*/

	return schema;
}

SLineageFileSchema Crypto::Encrypt(const char* inBuffer)
{
	SLineageFileSchema schema;

	/*schema.type = ECryptType::ENC;

	if (!ValidateHeader(schema, inBuffer))
	{
		return schema;
	}

	if (!SetCryptResultToBuffer(schema, inBuffer))
	{
		return schema;
	}*/

	return schema;
}
/*
bool Crypto::ValidateHeader(SLineageFileSchema& schema, const char*& inBuffer)
{
	string header;
	int version;

	auto validator = HeaderValidator(inBuffer);

	bool bIsValidHeader = validator.GetHeader(header);
	bool bIsValidVersion = validator.GetVersion(version);

	schema.header = header;
	schema.version = version;

	if (!bIsValidHeader)
	{
		schema.errorMsg = "Invalid Lineage2 header signature.";
	}
	else if (!bIsValidVersion)
	{
		schema.errorMsg = "This Lineage2 header version is not supported yet.";
	}
	
	return bIsValidHeader && bIsValidVersion;
}

bool Crypto::SetCryptResultToBuffer(SLineageFileSchema& schema, const char*& inBuffer)
{
	Algorithm* algorithm = nullptr;
	char* outBuffer = nullptr;

	if (!AlgorithmRegistry::GetInstance().Get(schema.version, algorithm))
	{
		schema.errorMsg = "This Lineage2 header version is not supported by any algorithm.";
		return false;
	}
	
	algorithm->SetBuffer(inBuffer);
	algorithm->GetResult(schema.type, outBuffer);

	if (outBuffer == nullptr)
	{
		schema.errorMsg = "An error occured while performing crypt operation on this file.";
		return false;
	}

	schema.buffer = outBuffer;
	algorithm->Reset();

	return true;
}*/