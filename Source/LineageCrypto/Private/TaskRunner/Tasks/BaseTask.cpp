
#include "TaskRunner/Tasks/BaseTask.h"

void BaseTask::SetCommand(unique_ptr<BaseCommand>& command)
{
	_command = move(command);
}

void BaseTask::Release()
{
	_command.reset();
	_command->Release();
}
