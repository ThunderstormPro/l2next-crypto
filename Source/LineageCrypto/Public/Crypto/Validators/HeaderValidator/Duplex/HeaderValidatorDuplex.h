#ifndef H_HEADER_VALIDATOR_DUPLEX
#define H_HEADER_VALIDATOR_DUPLEX

#include <memory>
#include "Shared/Structs/LineageFileSchema.h"
#include "Utils/Streams/Factory/StreamFactory.h"

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
	HeaderValidatorDuplex(SLineageFileSchema& schema);

protected:
	bool ValidateHeader(const std::shared_ptr<std::iostream>& stream);

	std::shared_ptr<std::iostream> Transform(const std::shared_ptr<std::iostream>& stream) override final;

private:
	SLineageFileSchema& schema;
};

#endif // H_HEADER_VALIDATOR_DUPLEX
