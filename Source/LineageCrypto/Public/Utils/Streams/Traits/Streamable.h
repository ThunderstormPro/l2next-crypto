#ifndef H_STREAMABLE
#define H_STREAMABLE

#include <memory>
#include <cassert>
#include <istream>
#include <fstream>
#include <iostream>
#include <ios>
#include <functional>
#include <vector>
#include <map>
#include "Utils/Streams/Structs/FileStreamOptions.h"
#include "Utils/Streams/Structs/BufStreamOptions.h"

class TStreamable
	: public std::streambuf
{
public:
	TStreamable() {};
	~TStreamable() {};

	bool IsStreaming();

	void Propagate(TStreamable* pipe, std::shared_ptr<std::iostream> stream);

	// TODO Implement this properly.
	void Start();
	void Pause() {};
	void Stop();

protected:
	virtual void Exec(std::shared_ptr<std::iostream> stream) = 0;

protected:
	bool bIsStreaming = false;
	std::shared_ptr<std::iostream> nextStream;

	/**
	* Call this method from derived class to set the read buffer.
	* @param std::vector<char> buffer buffer containing char data. 
	*/
	void SetBuffer(std::vector<char> buffer);

protected:
	/** Stream flow control. */
	virtual std::streambuf::int_type overflow(std::streambuf::int_type ch) override;
	virtual std::streambuf::int_type underflow() override;
	virtual std::streambuf::int_type uflow() override;

private:
	/** Stream flow control pointers for tracking positioning. */
	char* ptrBegin = nullptr;
	char* ptrEnd = nullptr;
	char* ptrCurrent = nullptr;

	/** Internal buffer. */
	std::vector<char> internalBuffer;
};

#endif // H_STREAMABLE
