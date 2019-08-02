#ifndef H_ON_VALIDATION_PASSED
#define H_ON_VALIDATION_PASSED

#include "Shared/Templates/EventTemplate.h"
#include "Crypto/Validators/HeaderValidator/Structs/ValidationResult.h"

namespace CryptoEvents
{
	class OnValidationPassed
		: public EventTemplate<SValidationResult>
	{
	public:
		virtual void Bind_OnValidationPassed(const Functor& func)
		{
			Add(func);
		}

		virtual void Exec_OnValidationPassed(const SValidationResult& result)
		{
			Call(result);
		}
	};
}

#endif // H_ON_VALIDATION_PASSED
