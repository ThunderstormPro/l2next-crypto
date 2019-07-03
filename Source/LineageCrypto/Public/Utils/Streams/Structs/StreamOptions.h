#ifndef H_SBUFFER
#define H_SBUFFER

#include <string>

enum class EStreamTypes
{
	NO_TYPE,
	FILE,
	BUFFER
};

struct StreamOptions
{
	StreamOptions()
	{

	}

	StreamOptions(const StreamOptions& options)
	{

	}

	/* Readable chunk size in bytes. */
	size_t chunkSize = 64;

	virtual EStreamTypes GetType()
	{
		return EStreamTypes::NO_TYPE;
	}
};

#endif // H_SBUFFER
