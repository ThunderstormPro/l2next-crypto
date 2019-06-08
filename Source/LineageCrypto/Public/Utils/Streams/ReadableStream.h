#ifndef H_READABLE_STREAM
#define H_READABLE_STREAM

#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <streambuf>
#include "Utils/Streams/Structs/Buffer.h"
#include "Utils/Streams/DuplexStream.h"
#include "Utils/Streams/WritableStream.h"

class ReadableStream : public std::streambuf
{
public:
	ReadableStream(const std::string& fname) : internalstream(std::ifstream(fname, std::ios::binary))
	{

	}

	static std::shared_ptr<ReadableStream> Create(const std::string& fname);

public:
	std::shared_ptr<DuplexStream> Pipe(std::shared_ptr<DuplexStream> stream);
	std::shared_ptr<WritableStream> Pipe(std::shared_ptr<WritableStream> stream);
	void OnRead();

private:
	std::shared_ptr<DuplexStream> duplexPipePtr;
	std::shared_ptr<WritableStream> wstreamPipePtr;
	std::ifstream internalstream;
};

#endif // H_READABLE_STREAM
