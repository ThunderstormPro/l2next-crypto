#include "Utils/Streams/Traits/Writable.h"

void TWritable::WriteFile(StreamOptions & options, std::shared_ptr<std::iostream> stream)
{
	// Cast to file stream options.
	auto _options = static_cast<SFileStreamOptions&>(options);

	// Get buffer for writing.
	std::vector<char> buffer(std::istreambuf_iterator<char>{*stream.get()}, {});

	// Create & write to file stream.
	fileStream = std::make_shared<std::ofstream>(_options.GetOutputFilePath(), std::ios::binary);
	fileStream->write(buffer.data(), buffer.size());
}

void TWritable::WriteBuffer(StreamOptions & options, std::shared_ptr<std::iostream> stream)
{
	// Cast to buf stream options.
	auto _options = static_cast<SBufStreamOptions&>(options);

	// Get buffer for writing.
	std::vector<char> buffer(std::istreambuf_iterator<char>{*stream.get()}, {});

	// Create & write to this memstream.
	bufStream = std::make_shared<std::iostream>(this);
	bufStream->write(buffer.data(), buffer.size());

	SetBuffer(buffer);
}
