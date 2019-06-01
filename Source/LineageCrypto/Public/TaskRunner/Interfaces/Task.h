#ifndef H_TASK
#define H_TASK

#include <functional>
#include <memory>
#include "TaskRunner/Commands/BaseCommand.h"

using namespace::std;

class ITask
{
protected:
	virtual ~ITask() {}

	virtual void Run() = 0;
	virtual void SetCommand(unique_ptr<BaseCommand>& command) = 0;
	virtual void OnTaskPassed(function<void(BaseCommand&)> callback) = 0;
	virtual void OnTaskFailed(function<void(BaseCommand&)> callback) = 0;
	virtual void Release() = 0;
};

#endif // H_TASK
