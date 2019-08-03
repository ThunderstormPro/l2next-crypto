#ifndef H_VALIDATION_RESULT
#define H_VALIDATION_RESULT

#include <string>
#include "Crypto/Enums/HeaderVersion.h"

struct SValidationResult
{
	EHeaderVersion version = NOT_IMPL;
	std::string message = "";
};


#endif // H_VALIDATION_RESULT
