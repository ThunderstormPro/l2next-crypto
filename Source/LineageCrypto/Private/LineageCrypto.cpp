#include "LineageCrypto.h"


void LineageCrypto::Enqueue(BaseCommand& cmnd)
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

void LineageCrypto::OnPassed(const function<void(L2Command&)> callback)
{
	TaskRunner::GetInstance().OnTaskPassed([callback](BaseCommand& cmnd) -> void {
		callback(cmnd);
	});
}

void LineageCrypto::OnFailed(const function<void(L2Command&)> callback)
{
	TaskRunner::GetInstance().OnTaskFailed([callback](BaseCommand& cmnd) -> void {
		callback(cmnd);
	});
}
