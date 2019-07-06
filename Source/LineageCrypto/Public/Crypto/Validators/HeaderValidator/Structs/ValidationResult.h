#ifndef H_VALIDATION_ERROR
#define H_VALIDATION_ERROR

#include <string>
#include "Crypto/Enums/HeaderVersion.h"

struct SValidationResult
{
	EHeaderVersion version = EHeaderVersion::NOT_IMPL;
	std::string message = "";
};


#endif // H_ON_VALIDATION_FAILED
