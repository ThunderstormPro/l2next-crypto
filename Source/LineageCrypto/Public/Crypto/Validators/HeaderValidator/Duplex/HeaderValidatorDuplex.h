#ifndef H_HEADER_VALIDATOR_DUPLEX
#define H_HEADER_VALIDATOR_DUPLEX

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
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
	bool ValidateHeader(const std::shared_ptr<std::iostream>& stream)
	{
		string header;
		EHeaderVersion version;

		auto validator = HeaderValidator(stream);

		bool bIsValidHeader = validator.GetHeader(header);
		bool bIsValidVersion = validator.GetVersion(version);

		if (!bIsValidHeader)
		{
			SValidationResult result;
			result.version = (EHeaderVersion)version;
			result.message = "Invalid Lineage2 header signature.";

			Exec_OnValidationFailed(result);
		}
		else if (!bIsValidVersion)
		{
			SValidationResult result;
			result.version = (EHeaderVersion)version;
			result.message = "This Lineage2 header version is not supported yet.";

			Exec_OnValidationFailed(result);
		}

		SValidationResult result;
		result.version = (EHeaderVersion)version;

		Exec_OnValidationPassed(result);

		return bIsValidHeader && bIsValidVersion;
	}

	virtual std::shared_ptr<std::iostream> Transform(const std::shared_ptr<std::iostream>& stream) final
	{
		if (!ValidateHeader(stream))
		{
			Stop();
		}

		return stream;
	}
};

#endif // H_HEADER_VALIDATOR_DUPLEX
