#ifndef H_WRITABLE
#define H_WRITABLE

#include <fstream>
#include "Utils/Streams/Traits/Streamable.h"

class TWritable
	: public TStreamable
{

public:
	TWritable()
	{
	}

	void WriteFile(StreamOptions& options, std::shared_ptr<std::iostream> stream);
	void WriteBuffer(StreamOptions& options, std::shared_ptr<std::iostream> stream);

	std::shared_ptr<std::ofstream> GetFileStream()
	{
		return fileStream;
	}

	std::shared_ptr<std::iostream> GetBufStream()
	{
		return bufStream;
	}

private:
	std::shared_ptr<std::ofstream> fileStream;
	std::shared_ptr<std::iostream> bufStream;
};

#endif // H_WRITABLE
