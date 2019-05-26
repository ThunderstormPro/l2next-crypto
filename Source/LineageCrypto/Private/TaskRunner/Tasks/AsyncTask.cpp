
#include "TaskRunner/Tasks/AsyncTask.h"

AsyncTask::AsyncTask(BaseCommand& command)
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

void AsyncTask::OnTaskPassed(function<void(BaseCommand&)> callback)
{
	callbackPassed = callback;
}

void AsyncTask::OnTaskFailed(function<void(BaseCommand&)> callback)
{
	callbackFailed = callback;
}
