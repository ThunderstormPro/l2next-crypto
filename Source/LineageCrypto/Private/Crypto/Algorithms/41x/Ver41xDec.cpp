#include "Crypto/Algorithms/41x/Ver41xDec.h"

Ver41xDec::Ver41xDec(const char*& inBuffer) : inBuffer(inBuffer)
{
}

Ver41xDec::~Ver41xDec()
{

}

void Ver41xDec::Process(char*& outBuffer)
{
	std::string testOutput = "Placeholder output buffer.";

	tempBuffer = new char[testOutput.length() + 1];
	strcpy(tempBuffer, testOutput.c_str());

	outBuffer = tempBuffer;
}
