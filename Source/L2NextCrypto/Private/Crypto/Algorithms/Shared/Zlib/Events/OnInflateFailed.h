#ifndef H_ON_INFLATE_FAILED
#define H_ON_INFLATE_FAILED

#include "Shared/Templates/EventTemplate.h"

namespace CryptoEvents
{
	class OnInflateFailed
		: public EventTemplate<int>
	{
	public:
		virtual void Bind_OnInflateFailed(const Functor& func)
		{
			Add(func);
		}

		virtual void Exec_OnInflateFailed(const int& errorCode)
		{
			Call(errorCode);
		}
	};
}

#endif // H_ON_INFLATE_FAILED
