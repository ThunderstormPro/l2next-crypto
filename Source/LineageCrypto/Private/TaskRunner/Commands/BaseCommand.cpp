#include "TaskRunner/Commands/BaseCommand.h"

bool BaseCommand::Execute()
{
	return false;
}

void BaseCommand::Release()
{

}

ECryptoCommands L2Command::GetId() const
{
	return _id;
}

void L2Command::SetId(ECryptoCommands id)
{
	_id = id;
}
