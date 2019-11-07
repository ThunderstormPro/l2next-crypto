#ifndef H_DECRYPT_RESULT
#define H_DECRYPT_RESULT

#include "Utils/Streams/Structs/StreamExecResult.h"

struct SAlgorithmResult : SStreamExecResult
{
	int blocks = 0;
	size_t fileSize = 0;

	~SAlgorithmResult() = default;
};


#endif // H_VALIDATION_RESULT
