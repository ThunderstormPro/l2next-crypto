#ifndef H_TASK
#define H_TASK

#include <functional>
#include "TaskRunner/Commands/BaseCommand.h"

using namespace::std;

class ITask
{
protected:
	// TODO
	// Add task ID
	BaseCommand& _command;

	virtual void Run() = 0;
	virtual void OnTaskPassed(function<void(BaseCommand&)> callback) = 0;
	virtual void OnTaskFailed(function<void(BaseCommand&)> callback) = 0;

	ITask(BaseCommand& command) : _command(command) {}
	virtual ~ITask() {}
};

#endif // H_TASK
