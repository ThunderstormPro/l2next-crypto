#include "Utils/Streams/Traits/Readable.h"

void TReadable::ReadFileStream(StreamOptions & options)
{
	clock_t tStart = clock();

	// Create next stream from self.
	auto stream = std::make_shared<std::iostream>(this);

	// Get file stream specific options.
	auto _options = static_cast<SFileStreamOptions&>(options);

	// Open the file & get contents.
	fstream.open(_options.GetInputFilePath(), std::ios::in | std::ios::binary);
	std::vector<char> buffer(std::istreambuf_iterator<char>{fstream}, {});

	// Set internal stream buffer.
	SetBuffer(buffer);

	// Write data to next stream.
	stream->write(buffer.data(), buffer.size());

	double totalExecTime = (double)(clock() - tStart) / CLOCKS_PER_SEC;
	Exec_OnEnd(totalExecTime);

	nextStream = stream;
}

void TReadable::ReadBufferedStream(StreamOptions & options)
{
	clock_t tStart = clock();

	// Create next stream from self.
	auto stream = std::make_shared<std::iostream>(this);

	// Get file stream specific options.
	auto _options = static_cast<SBufStreamOptions&>(options);
	
	// Set buffer.
	std::vector<char> buffer(_options.GetBufferBeg(), _options.GetBufferEnd());
	SetBuffer(buffer);

	// Write data to next stream.
	stream->write(buffer.data(), buffer.size());

	double totalExecTime = (double)(clock() - tStart) / CLOCKS_PER_SEC;
	Exec_OnEnd(totalExecTime);

	nextStream = stream;
}

char * TReadable::GetBeginPos()
{
	return nullptr;
}

std::streampos TReadable::GetEndPos()
{
	return 0;
}
