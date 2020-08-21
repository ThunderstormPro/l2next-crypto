#ifndef H_ON_INFLATE_CHUNK
#define H_ON_INFLATE_CHUNK

#include "Shared/Templates/EventTemplate.h"

namespace CryptoEvents
{
	struct SInflatedChunk
	{
		unsigned int total = 0;
		unsigned int current = 0;
	};

	class OnInflateChunk
		: public EventTemplate<SInflatedChunk>
	{
	public:
		virtual void Bind_OnInflateChunk(const Functor& func)
		{
			Add(func);
		}

		virtual void Exec_OnInflateChunk(const SInflatedChunk& data)
		{
			Call(data);
		}
	};
}

#endif // H_ON_INFLATE_CHUNK