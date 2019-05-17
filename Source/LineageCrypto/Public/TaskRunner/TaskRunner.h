#ifndef H_TASK_RUNNER
#define H_TASK_RUNNER

#include <functional>
#include <vector>
#include <memory>
#include "Interfaces/Command.h"
#include "Tasks/AsyncTask.h"

using namespace::std;

// Todo create this as a singleton.
class TaskRunner
{
public:
	static TaskRunner& GetInstance()
	{
		static TaskRunner instance;
		return instance;
	};

	void Enqueue(ICommand& cmnd);
	void ExecuteAll();
	void Release();

	// Events.
	void OnTaskPassed(function<void(ICommand&)> callback);
	void OnTaskFailed(function<void(ICommand&)> callback);

private:
	vector<unique_ptr<AsyncTask>> _asyncTasks;

	TaskRunner() = default;
	~TaskRunner() = default;
	TaskRunner(const TaskRunner&) = delete;
	TaskRunner& operator=(const TaskRunner&) = delete;
};

#endif // H_TASK_RUNNER