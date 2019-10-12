#ifndef H_ON_END
#define H_ON_END

#include "Shared/Templates/EventTemplate.h"

namespace StreamEvents
{
	class OnEnd
		: public EventTemplate<double>
	{

	public:
		virtual void Bind_OnEnd(const Functor& func)
		{
			Add(func);
		}

		virtual void Exec_OnEnd(double duration)
		{
			Call(duration);
		}
	};
}

#endif // H_ON_END
