#ifndef H_ASYNC_TASK
#define H_ASYNC_TASK

#include <functional>
#include "TaskRunner/Interfaces/Task.h"

using namespace::std;

class AsyncTask 
	: public ITask
{
public:
	AsyncTask(ICommand& command);
	~AsyncTask();
	void Run();

	function<void(ICommand&)> callbackPassed;
	function<void(ICommand&)> callbackFailed;

	virtual void OnTaskPassed(function<void(ICommand&)> callback) override;
	virtual void OnTaskFailed(function<void(ICommand&)> callback) override;
};

#endif // H_ASYNC_TASK