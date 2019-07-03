#ifndef H_ASYNC_TASK
#define H_ASYNC_TASK

#include <functional>
#include "TaskRunner/Commands/BaseCommand.h"
#include "TaskRunner/Tasks/BaseTask.h"

using namespace::std;

class AsyncTask
	: public BaseTask
{
public:
	AsyncTask();
	~AsyncTask();
	virtual void Run() override;
	virtual void OnTaskPassed(function<void(BaseCommand&)> callback) override;
	virtual void OnTaskFailed(function<void(BaseCommand&)> callback) override;
	virtual void Release() override {};

private:
	function<void(BaseCommand&)> callbackPassed;
	function<void(BaseCommand&)> callbackFailed;
};

#endif // H_ASYNC_TASK
