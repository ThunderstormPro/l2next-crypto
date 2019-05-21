#ifndef H_ASYNC_TASK
#define H_ASYNC_TASK

#include <functional>
#include "TaskRunner/Commands/BaseCommand.h"
#include "TaskRunner/Interfaces/Task.h"

using namespace::std;

class AsyncTask 
	: public ITask
{
public:
	AsyncTask(BaseCommand& command);
	~AsyncTask();
	void Run();

	function<void(BaseCommand&)> callbackPassed;
	function<void(BaseCommand&)> callbackFailed;

	virtual void OnTaskPassed(function<void(BaseCommand&)> callback) override;
	virtual void OnTaskFailed(function<void(BaseCommand&)> callback) override;
};

#endif // H_ASYNC_TASK
