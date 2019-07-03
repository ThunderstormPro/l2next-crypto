
#include "TaskRunner/Tasks/AsyncTask.h"

AsyncTask::AsyncTask()
{
	
}

AsyncTask::~AsyncTask()
{

}

void AsyncTask::Run()
{
	// TODO
	// Execute command on an available thread.
	bool bPassed = _command->Execute();

	if (bPassed)
	{
		callbackPassed(*_command.get());
	} 
	else
	{
		callbackFailed(*_command.get());
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
