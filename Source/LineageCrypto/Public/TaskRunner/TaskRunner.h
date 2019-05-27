#ifndef H_TASK_RUNNER
#define H_TASK_RUNNER

#include <functional>
#include <vector>
#include <memory>
#include "Commands/BaseCommand.h"
#include "Tasks/AsyncTask.h"

using namespace::std;

class TaskRunner
{
public:
	static TaskRunner& GetInstance()
	{
		static TaskRunner instance;
		return instance;
	};

	void Enqueue(unique_ptr<BaseCommand>& cmnd);
	void ExecuteAll();
	void ReleaseAll();

	// Events.
	void OnTaskPassed(function<void(BaseCommand&)> callback);
	void OnTaskFailed(function<void(BaseCommand&)> callback);

private:
	vector<unique_ptr<AsyncTask>> _asyncTasks;

	TaskRunner() = default;
	~TaskRunner() = default;
	TaskRunner(const TaskRunner&) = delete;
	TaskRunner& operator=(const TaskRunner&) = delete;
};

#endif // H_TASK_RUNNER
