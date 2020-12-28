#ifndef H_HEADER_VALIDATOR_DUPLEX
#define H_HEADER_VALIDATOR_DUPLEX

#include <memory>
#include "Utils/Streams/DuplexStream.h"
#include "Crypto/Validators/HeaderValidator/HeaderValidator.h"
#include "Crypto/Validators/HeaderValidator/Events/OnValidationPassed.h"
#include "Crypto/Validators/HeaderValidator/Events/OnValidationFailed.h"

using namespace::L2NextCryptoStreams;
using namespace::CryptoEvents;

class HeaderValidatorDuplex
	: public DuplexStream
	, public OnValidationPassed
	, public OnValidationFailed
{
protected:
	std::stringstream& Transform(std::stringstream& stream) override final;
};

#endif // H_HEADER_VALIDATOR_DUPLEX
