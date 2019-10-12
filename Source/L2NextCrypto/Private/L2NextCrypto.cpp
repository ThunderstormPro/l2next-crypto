#include "L2NextCrypto.h"


void L2NextCrypto::Enqueue(unique_ptr<BaseCommand>& cmnd)
{
	TaskRunner::GetInstance().Enqueue(cmnd);
}

void L2NextCrypto::ExecuteAll()
{
	TaskRunner::GetInstance().ExecuteAll();
}

void L2NextCrypto::ReleaseAll()
{
	TaskRunner::GetInstance().ReleaseAll();
}

void L2NextCrypto::OnPassed(const function<void(L2Command&)> callback)
{
	TaskRunner::GetInstance().OnTaskPassed([callback](BaseCommand& cmnd) -> void {
		callback(cmnd);
	});
}

void L2NextCrypto::OnFailed(const function<void(L2Command&)> callback)
{
	TaskRunner::GetInstance().OnTaskFailed([callback](BaseCommand& cmnd) -> void {
		callback(cmnd);
	});
}
