#ifndef H_PIPABLE
#define H_PIPABLE

#include <iostream>
#include <memory>
#include "Utils/Streams/Traits/Streamable.h"
#include "Utils/Streams/Traits/Writable.h"
#include "Utils/Streams/Traits/Transformable.h"

template<class T, class W>
class TPipable
{
	
public:
	TPipable() { }

	virtual ~TPipable() { }

	T* Pipe(const std::shared_ptr<T>& pipe)
	{
		SetNextPipe(pipe);
		return pipe.get();
	}

	W* Pipe(const std::shared_ptr<W>& pipe)
	{
		SetNextPipe(pipe);
		return pipe.get();
	}

	TStreamable* GetPipe() const
	{
		return nextPipe.get();
	};

private:
	template<typename P>
	void SetNextPipe(const std::shared_ptr<P>& pipe)
	{
		nextPipe = std::static_pointer_cast<TStreamable>(pipe);
	}

	std::shared_ptr<TStreamable> nextPipe;
};

#endif // H_PIPABLE
