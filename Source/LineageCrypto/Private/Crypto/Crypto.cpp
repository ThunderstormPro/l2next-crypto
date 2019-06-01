#include "Crypto/Crypto.h"


SLineageFileSchema Crypto::Decrypt(char* buffer)
{
	SLineageFileSchema schema;
	string header = GetHeaderString(buffer);
	schema.header = header;

	if (header == INVALID_HEADER)
	{
		schema.errorMsg = "Buffer does not contain a valid Lineage2 header signature.";
		return schema;
	}

	char* result = { 0 };
	short version = GetHeaderVersion(header);
	schema.version = version;

	const auto& algorithm = GetAlgorithm(ECryptType::DEC, version);
	
	if (algorithm == nullptr)
	{
		schema.errorMsg = "Header version is not supported by any enc/dec algorithm.";
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

string Crypto::GetHeaderString(char* buffer)
{
	string header(buffer, LINEAGE_HEADER_SIZE);
	header.erase(remove(header.begin(), header.end(), NULL_TERMINATOR_CHR), header.end());

	if (!regex_search(header.c_str(), LINEAGE_HEADER_SIGNATURE))
	{
		return INVALID_HEADER;
	}
	
	return header;
}

int Crypto::GetHeaderVersion(string header)
{
	header.erase(header.begin(), header.end() - 3);
	return stoi(header);
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
