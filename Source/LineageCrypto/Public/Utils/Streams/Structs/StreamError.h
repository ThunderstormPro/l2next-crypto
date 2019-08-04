#ifndef H_STREAM_EXEC_RESULT
#define H_STREAM_EXEC_RESULT

#include <string>

enum ExecResultStatus
{
	OK = 0, // Values of 0 or more.
	ERROR = -1 // Values less then 0.
};

struct SStreamExecResult
{
	int status = OK;
	std::string msg = "";
};

#endif // H_STREAM_EXEC_RESULT
