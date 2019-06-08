#ifndef H_DUPLEX_STREAM
#define H_DUPLEX_STREAM

#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <streambuf>
#include "Utils/Streams/WritableStream.h"
#include "Utils/Streams/Structs/Buffer.h"

class DuplexStream : public std::streambuf, public SWritable
{
public:
	DuplexStream(std::string name);

	static std::shared_ptr<DuplexStream> Create(std::string name);

public:
	std::shared_ptr<DuplexStream> DuplexStream::Pipe(std::shared_ptr<DuplexStream> stream)
	{
		duplexPipePtr = stream;
		return stream;
	};

	std::shared_ptr<WritableStream> DuplexStream::Pipe(std::shared_ptr<WritableStream> stream)
	{
		wstreamPipePtr = stream;
		return stream;
	};

	virtual void Transform() override;
private:
	std::string name;
	std::shared_ptr<DuplexStream> duplexPipePtr;
	std::shared_ptr<WritableStream> wstreamPipePtr;
};
#endif // H_DUPLEX_STREAM
