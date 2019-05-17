#include "LineageCrypto.h"

void LineageCrypto::Enqueue(ICommand& cmnd)
{
	TaskRunner::GetInstance().Enqueue(cmnd);
}

void LineageCrypto::ExecuteAll()
{
	TaskRunner::GetInstance().ExecuteAll();
}

void LineageCrypto::Release()
{
	TaskRunner::GetInstance().Release();
}

void LineageCrypto::OnPassed(function<void(ICommand&)> callback)
{
	TaskRunner::GetInstance().OnTaskPassed(callback);
}

void LineageCrypto::OnFailed(function<void(ICommand&)> callback)
{
	TaskRunner::GetInstance().OnTaskFailed(callback);
}
