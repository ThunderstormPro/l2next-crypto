#include <string>
#include "Crypto/Validators/HeaderValidator/Duplex/HeaderValidatorDuplex.h"
#include "Crypto/Enums/HeaderVersion.h"


HeaderValidatorDuplex::HeaderValidatorDuplex(SLineageFileSchema& schema): schema(schema)
{
}

bool HeaderValidatorDuplex::ValidateHeader(const std::shared_ptr<std::iostream>& stream)
{
	string header;
	EHeaderVersion version;

	auto validator = HeaderValidator(stream);

	const bool bIsValidHeader = validator.GetHeader(header);
	const bool bIsValidVersion = validator.GetVersion(version);

	if (!bIsValidHeader)
	{
		schema.version = static_cast<EHeaderVersion>(version);
		schema.errorMsg = "Invalid Lineage2 header signature.";

		Exec_OnValidationFailed(SValidationResult{schema.version, schema.errorMsg});
	}
	else if (!bIsValidVersion)
	{
		schema.version = static_cast<EHeaderVersion>(version);
		schema.errorMsg = "This Lineage2 header version is not supported yet.";

		Exec_OnValidationFailed(SValidationResult{schema.version, schema.errorMsg});
	}

	schema.version = static_cast<EHeaderVersion>(version);
	schema.header = header;

	Exec_OnValidationPassed(SValidationResult{schema.version});

	return bIsValidHeader && bIsValidVersion;
}

std::shared_ptr<std::iostream> HeaderValidatorDuplex::Transform(const std::shared_ptr<std::iostream>& stream)
{
	if (!ValidateHeader(stream))
	{
		Stop();
	}

	return stream;
}
