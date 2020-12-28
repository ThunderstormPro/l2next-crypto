#ifndef H_ON_DECRYPT_CHUNK
#define H_ON_DECRYPT_CHUNK
#include "Shared/Templates/EventTemplate.h"

namespace CryptoEvents
{
	struct SDecryptedChunk {
		unsigned int current = 0;
		unsigned int total = 0;
	};

	class OnDecryptChunk
		: public EventTemplate<SDecryptedChunk>
	{

	public:
		virtual void Bind_OnDecryptChunk(const Functor& func)
		{
			Add(func);
		}

		virtual void Exec_OnDecryptChunk(const SDecryptedChunk& data)
		{
			Call(data);
		}
	};
}

#endif // H_ON_DECRYPT_CHUNK
