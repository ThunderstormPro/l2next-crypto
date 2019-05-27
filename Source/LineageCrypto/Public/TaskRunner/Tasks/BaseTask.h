#ifndef H_BASE_TASK
#define H_BASE_TASK

#include <functional>
#include "TaskRunner/Commands/BaseCommand.h"
#include "TaskRunner/Interfaces/Task.h"

using namespace::std;

class BaseTask
	: public ITask
{
public:
	BaseTask() {};
	~BaseTask() {};
	virtual void Run() override {};
	virtual void SetCommand(unique_ptr<BaseCommand>& command) override;

	virtual void OnTaskPassed(function<void(BaseCommand&)> callback) override {};
	virtual void OnTaskFailed(function<void(BaseCommand&)> callback) override {};
	virtual void Release() override;
protected:
	unique_ptr<BaseCommand> _command;
};

#endif // H_BASE_TASK
