#ifndef H_ON_DECRYPT_PASSED
#define H_ON_DECRYPT_PASSED
#include "Shared/Templates/EventTemplate.h"
#include "Crypto/Algorithms/Base/Structs/DecryptResult.h"

namespace CryptoEvents
{
	class OnDecryptPassed
		: public EventTemplate<SAlgorithmResult>
	{

	public:
		virtual void Bind_OnDecryptPassed(const Functor& func)
		{
			Add(func);
		}

		virtual void Exec_OnDecryptPassed(const SAlgorithmResult& result)
		{
			Call(result);
		}
	};
}

#endif // H_ON_DECRYPT_PASSED
