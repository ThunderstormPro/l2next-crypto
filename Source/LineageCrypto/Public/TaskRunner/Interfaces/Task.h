#ifndef H_TASK
#define H_TASK

#include "Command.h"
#include <functional>

using namespace::std;

class ITask
{
protected:
	// TODO
	// Add task ID
	ICommand& _command;

	virtual void Run() = 0;
	virtual void OnTaskPassed(function<void(ICommand&)> callback) = 0;
	virtual void OnTaskFailed(function<void(ICommand&)> callback) = 0;

	ITask(ICommand& command) : _command(command) {}
	virtual ~ITask() {}
};

#endif // H_TASK
