#ifndef H_ON_DECRYPT_FAILED
#define H_ON_DECRYPT_FAILED
#include "Shared/Templates/EventTemplate.h"

namespace CryptoEvents
{
	class OnDecryptFailed
		: public EventTemplate<int>
	{

	public:
		virtual void Bind_OnDecryptFailed(const Functor& func)
		{
			Add(func);
		}

		virtual void Exec_OnDecryptFailed(int& result)
		{
			Call(result);
		}
	};
}

#endif // H_ON_DECRYPT_FAILED
