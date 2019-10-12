#ifndef H_ON_INFLATE_FAILED
#define H_ON_INFLATE_FAILED

#include "Shared/Templates/EventTemplate.h"
#include "Crypto/Algorithms/Shared/ZLib/Structs/zlibResult.h"

namespace CryptoEvents
{
	class OnInflateFailed
		: public EventTemplate<SZlibResult>
	{
	public:
		virtual void Bind_OnInflateFailed(const Functor& func)
		{
			Add(func);
		}

		virtual void Exec_OnInflateFailed(const SZlibResult& result)
		{
			Call(result);
		}
	};
}

#endif // H_ON_INFLATE_FAILED
