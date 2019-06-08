#ifndef H_INPUT_READER
#define H_INPUT_READER

#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <streambuf>
#include "Utils/Streams/Structs/Buffer.h"

class WritableStream : public std::streambuf, SWritable
{
public:
	WritableStream(const std::string& fname)
		: internalstream(std::ofstream(fname, std::ios::binary))
	{

	}

	static std::shared_ptr<WritableStream> Create(const std::string& fname)
	{
		return std::make_shared<WritableStream>(fname);
	}

public:

	virtual void Transform() override;
private:
	std::ofstream internalstream;
};

#endif
