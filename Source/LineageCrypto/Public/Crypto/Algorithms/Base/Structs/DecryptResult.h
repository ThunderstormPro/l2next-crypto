#ifndef H_ON_DECRYPT_PASSED
#define H_ON_DECRYPT_PASSED
#include "Shared/Templates/EventTemplate.h"

namespace CryptoEvents
{
	class OnDecryptPassed
		: public EventTemplate<SValidationResult>
	{

	public:
		virtual void Bind_OnValidationPassed(const Functor& func)
		{
			Add(func);
		}

		virtual void Exec_OnValidationPassed(SValidationResult result)
		{
			Call(result);
		}
	};
}

#endif // H_ON_DECRYPT_PASSED
