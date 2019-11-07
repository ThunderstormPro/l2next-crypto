#ifndef H_ON_DECRYPT_FAILED
#define H_ON_DECRYPT_FAILED
#include "Shared/Templates/EventTemplate.h"
#include "Crypto/Algorithms/Base/Structs/DecryptResult.h"

namespace CryptoEvents
{
	class OnDecryptFailed
		: public EventTemplate<SAlgorithmResult>
	{

	public:
		virtual void Bind_OnDecryptFailed(const Functor& func)
		{
			Add(func);
		}

		virtual void Exec_OnDecryptFailed(SAlgorithmResult result)
		{
			Call(result);
		}
	};
}

#endif // H_ON_DECRYPT_FAILED
