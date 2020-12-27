#ifndef H_ON_TRANSFORM_CHUNK
#define H_ON_TRANSFORM_CHUNK

#include "Shared/Templates/EventTemplate.h"

namespace CryptoEvents
{
	struct STransformedChunk
	{
		unsigned int current = 0;
		unsigned int total = 0;
	};

	class OnTransformChunk
		: public EventTemplate<STransformedChunk>
	{
	public:
		virtual void Bind_OnTransformChunk(const Functor& func)
		{
			Add(func);
		}

		virtual void Exec_OnTransformChunk(const STransformedChunk& data)
		{
			Call(data);
		}
	};
}

#endif // H_ON_TRANSFORM_CHUNK