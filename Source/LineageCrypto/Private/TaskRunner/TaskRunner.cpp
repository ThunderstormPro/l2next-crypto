#include "TaskRunner/TaskRunner.h"

void TaskRunner::Enqueue(BaseCommand& cmnd)
{
	// TODO Multithreading
	unique_ptr<AsyncTask> task = make_unique<AsyncTask>(cmnd);
	_asyncTasks.push_back(move(task));
}

void TaskRunner::ExecuteAll()
{
	for (auto const& task : _asyncTasks)
	{
		task->Run();
	}
}

void TaskRunner::Release()
{
	if (!_asyncTasks.empty())
	{
		_asyncTasks.clear();
	}
}

void TaskRunner::OnTaskPassed(function<void(BaseCommand&)> callback)
{
	for (auto const& task : _asyncTasks)
	{
		task->OnTaskPassed(callback);
	}
}

void TaskRunner::OnTaskFailed(function<void(BaseCommand&)> callback)
{
	for (auto const& task : _asyncTasks)
	{
		task->OnTaskFailed(callback);
	}
}
