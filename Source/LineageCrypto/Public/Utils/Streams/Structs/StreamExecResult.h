#ifndef H_STREAM_EXEC_RESULT
#define H_STREAM_EXEC_RESULT

#include <string>

struct SStreamExecResult
{
	int errorCode;
	std::string msg;

	virtual ~SStreamExecResult() = default;
};



#endif // H_STREAM_EXEC_RESULT
