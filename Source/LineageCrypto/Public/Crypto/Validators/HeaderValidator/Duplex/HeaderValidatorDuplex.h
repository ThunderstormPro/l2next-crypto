#ifndef H_HEADER_VALIDATOR_DUPLEX
#define H_HEADER_VALIDATOR_DUPLEX

#include <string>
#include <memory>
#include "Shared/Structs/LineageFileSchema.h"
#include "Utils/Streams/Factory/StreamFactory.h"
#include "Crypto/Enums/HeaderVersion.h"
#include "Crypto/Validators/HeaderValidator/HeaderValidator.h"
#include "Crypto/Validators/HeaderValidator/Events/OnValidationPassed.h"
#include "Crypto/Validators/HeaderValidator/Events/OnValidationFailed.h"

/*
* TODO For cleanup task.
* 1. Rename namespaces to an uniform & consistent model.
* 2. Extract error codes / messages to separate struct.
*/

using namespace::LineageCryptoStreams;
using namespace::CryptoEvents;

class HeaderValidatorDuplex
	: public DuplexStream
	, public OnValidationPassed
	, public OnValidationFailed
{
public:
	HeaderValidatorDuplex(SLineageFileSchema& schema)
		:schema(schema)
	{
		
	}

protected:
	bool ValidateHeader(const std::shared_ptr<std::iostream>& stream)
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

			Exec_OnValidationFailed(SValidationResult{ schema.version, schema.errorMsg });
		}
		else if (!bIsValidVersion)
		{
			schema.version = static_cast<EHeaderVersion>(version);
			schema.errorMsg = "This Lineage2 header version is not supported yet.";

			Exec_OnValidationFailed(SValidationResult{ schema.version, schema.errorMsg });
		}

		schema.version = static_cast<EHeaderVersion>(version);
		schema.header = header;

		Exec_OnValidationPassed(SValidationResult{ schema.version });

		return bIsValidHeader && bIsValidVersion;
	}

	std::shared_ptr<std::iostream> Transform(const std::shared_ptr<std::iostream>& stream) override final
	{
		if (!ValidateHeader(stream))
		{
			Stop();
		}

		return stream;
	}

private:
	SLineageFileSchema& schema;
};

#endif // H_HEADER_VALIDATOR_DUPLEX
