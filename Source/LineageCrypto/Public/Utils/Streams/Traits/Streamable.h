#ifndef H_STREAMABLE
#define H_STREAMABLE

#include <memory>
#include <cassert>
#include <fstream>
#include <istream>
#include <iostream>
#include <sstream>
#include <streambuf>
#include <stdio.h>
#include <ios>
#include <functional>
#include <vector>
#include <map>
#include "Utils/Streams/Structs/FileStreamOptions.h"
#include "Utils/Streams/Structs/BufStreamOptions.h"
#include <Utils/Streams/Structs/StreamExecResult.h>


class TStreamable
	: public std::streambuf
{
public:
	TStreamable() = default;
	//~TStreamable() = default;

	bool bIsStreaming = false;

	// TODO Implement this properly.
	void Start();
	void Pause() {};
	void Stop();

	void Propagate(TStreamable* pipe, std::shared_ptr<std::iostream> stream) const;
	std::shared_ptr<SStreamExecResult> TStreamable::GetExecResult() const;
protected:
	virtual void Exec(std::shared_ptr<std::iostream> stream) = 0;
	virtual void SetExecResult(const std::shared_ptr<SStreamExecResult>& result);
	
	std::shared_ptr<std::iostream> nextStream;
	/**
	* Call this method from derived class to set the read buffer.
	* @param std::vector<char> buffer buffer containing char data. 
	*/
	void SetBuffer(std::vector<char> buffer);

	/** Stream flow control. */
	std::streambuf::int_type overflow(std::streambuf::int_type ch) override;
	std::streambuf::int_type underflow() override;
	std::streambuf::int_type uflow() override;

private:
	/** Stream flow control pointers for tracking positioning. */
	char* ptrBegin = nullptr;
	char* ptrEnd = nullptr;
	char* ptrCurrent = nullptr;

	/** Internal buffer. */
	std::vector<char> internalBuffer;

	std::shared_ptr<SStreamExecResult> execResult;
};

#endif // H_STREAMABLE
