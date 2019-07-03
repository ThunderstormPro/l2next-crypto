#ifndef H_BUF_STREAM_OPTIONS
#define H_BUF_STREAM_OPTIONS

#include "StreamOptions.h"

struct SBufStreamOptions : public StreamOptions
{
public:
	SBufStreamOptions(const SBufStreamOptions& options)
		: beg(options.beg)
		, end(options.end)
	{

	}

	SBufStreamOptions(const char* beg, const char* end)
		: beg(beg)
		, end(end) 
	{ 
	}

public:
	/* Used to determine current read progress. */
	size_t bufferWidth = 0;

public:

	virtual EStreamTypes GetType() final
	{
		return EStreamTypes::BUFFER;
	}

	const char* GetBufferBeg()
	{
		return beg;
	}

	const char* GetBufferEnd()
	{
		return end;
	}

private:
	const char* beg;
	const char* end;
};

#endif // H_BUF_STREAM_OPTIONS
