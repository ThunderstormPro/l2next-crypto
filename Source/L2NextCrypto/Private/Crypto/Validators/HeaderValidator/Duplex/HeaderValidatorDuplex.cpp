#include <string>
#include "Crypto/Validators/HeaderValidator/Duplex/HeaderValidatorDuplex.h"
#include "Crypto/Enums/HeaderVersion.h"

std::stringstream& HeaderValidatorDuplex::Transform(std::stringstream& stream)
{
	std::string header;
	std::string errorMsg;
	EHeaderVersion version;

	auto validator = HeaderValidator(stream);

	const bool bIsValidHeader = validator.GetHeader(header);
	const bool bIsValidVersion = validator.GetVersion(version);

	if (!bIsValidHeader)
	{
		errorMsg = "Invalid Lineage2 header signature.";
		Exec_OnValidationFailed(SValidationResult{ version, errorMsg });
	}
	else if (!bIsValidVersion)
	{
		errorMsg = "Invalid or unsupported Lineage2 header version.";
		Exec_OnValidationFailed(SValidationResult{ version, errorMsg });
	}

	Exec_OnValidationPassed(SValidationResult{ version });

	return stream;
}
