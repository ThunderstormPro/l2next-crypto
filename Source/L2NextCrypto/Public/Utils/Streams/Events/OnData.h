#ifndef H_ON_DATA
#define H_ON_DATA

#include "Shared/Templates/EventTemplate.h"

namespace StreamEvents {

	class OnData
		: public EventTemplate<char*>
	{

	public:
		virtual void Bind_OnData(const Functor& func)
		{
			Add(func);
		}

		virtual void Exec_OnData(char* chunk)
		{
			Call(chunk);
		}
	};
}

#endif // H_ON_DATA
