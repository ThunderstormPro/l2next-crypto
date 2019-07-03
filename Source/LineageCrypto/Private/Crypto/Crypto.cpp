#include "Crypto/Crypto.h"

SLineageFileSchema Crypto::Decrypt(const char* inBuffer)
{
	SLineageFileSchema schema;

	schema.type = ECryptType::DEC;

	if (!ValidateHeader(schema, inBuffer))
	{
		return schema;
	}

	if (!SetCryptResultToBuffer(schema, inBuffer))
	{
		return schema;
	}

	return schema;
}

SLineageFileSchema Crypto::Encrypt(const char* inBuffer)
{
	SLineageFileSchema schema;

	schema.type = ECryptType::ENC;

	if (!ValidateHeader(schema, inBuffer))
	{
		return schema;
	}

	if (!SetCryptResultToBuffer(schema, inBuffer))
	{
		return schema;
	}

	return schema;
}

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
	AlgorithmBase* algorithm = nullptr;
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
}