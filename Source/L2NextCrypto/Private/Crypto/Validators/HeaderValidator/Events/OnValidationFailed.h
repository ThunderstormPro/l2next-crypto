#ifndef H_ON_VALIDATION_FAILED
#define H_ON_VALIDATION_FAILED

#include <string>
#include "Shared/Templates/EventTemplate.h"
#include "Crypto/Enums/HeaderVersion.h"
#include "Crypto/Validators/HeaderValidator/Structs/ValidationResult.h"

namespace CryptoEvents
{
	class OnValidationFailed
		: public EventTemplate<SValidationResult>
	{
	public:
		virtual void Bind_OnValidationFailed(const Functor& func)
		{
			Add(func);
		}

		virtual void Exec_OnValidationFailed(const SValidationResult& result)
		{
			Call(result);
		}
	};
}

#endif // H_ON_VALIDATION_FAILED
