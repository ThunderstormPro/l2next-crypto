#include "TaskRunner/Interfaces/Command.h"
#include "TaskRunner/Tasks/AsyncTask.h"

AsyncTask::AsyncTask(ICommand& command) 
	: ITask(command)
{
	
}

AsyncTask::~AsyncTask()
{
}

void AsyncTask::Run()
{
	// Execute command on an available thread.
	bool bPassed = _command.Execute();

	if (bPassed)
	{
		callbackPassed(_command);
	} 
	else
	{
		callbackFailed(_command);
	}
}

void AsyncTask::OnTaskPassed(function<void(ICommand&)> callback)
{
	callbackPassed = callback;
}

void AsyncTask::OnTaskFailed(function<void(ICommand&)> callback)
{
	callbackFailed = callback;
}
