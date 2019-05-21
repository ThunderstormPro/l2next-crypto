#include "Crypto/Crypto.h"

SLineageFileSchema Crypto::Decrypt(char* buffer)
{
	char* result = nullptr;
	string header = GetHeader(buffer);
	short version = GetHeaderVersion(header);

	SLineageFileSchema schema;
	schema.header = header;
	schema.version = version;
	
	const auto& algorithm = GetAlgorithm(ECryptType::DEC, version);
	
	if (algorithm == nullptr)
	{
		algorithm->Reset();
		schema.errorMsg = "No enc/dec algorithm could be found for provided version.";
		return schema;
	}
	
	algorithm->SetInputData(buffer);
	algorithm->GetExecResult(result);

	if (result == nullptr)
	{
		algorithm->Reset();
		schema.errorMsg = "Invalid Lineage 2 file provided. Could not perform operation.";
		return schema;
	}

	schema.buffer = result;
	algorithm->Reset();

	return schema;
}

SLineageFileSchema Crypto::Encrypt(char* buffer)
{
	// TODO
	SLineageFileSchema schema;

	schema.header = "Lineage2Ver413";

	return schema;
}

string Crypto::GetHeader(char* buffer)
{
	// Sample.
	return string("Lineage2Ver413");
}

short Crypto::GetHeaderVersion(string& header)
{
	// Sample.
	return 413;
}

unique_ptr<AlgorithmBase> Crypto::GetAlgorithm(ECryptType type, short& version)
{
	switch (version)
	{
		case 413 :
		{
			return type == ECryptType::ENC
				? GetAlgorithmWithClass<Enc41x>()
				: GetAlgorithmWithClass<Dec41x>();
		}

		default:
			return nullptr;
	}
}
