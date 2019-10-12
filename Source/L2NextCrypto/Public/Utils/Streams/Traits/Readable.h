#ifndef H_READABLE
#define H_READABLE

#include <algorithm>
#include <time.h>
#include "Streamable.h"
#include "Utils/Streams/Events/OnEnd.h"


class TReadable
	: public TStreamable
	, public StreamEvents::OnEnd
{
	std::ifstream fstream;

public:

	TReadable()
	{
	}

	void ReadFileStream(StreamOptions& options);
	void ReadBufferedStream(StreamOptions& options);

protected:
	virtual char* GetBeginPos();
	virtual std::streampos GetEndPos();
};

#endif // H_READABLE
