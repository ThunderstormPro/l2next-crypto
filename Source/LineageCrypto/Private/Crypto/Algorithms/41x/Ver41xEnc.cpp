#include "Crypto/Algorithms/41x/Ver41xEnc.h"

Ver41xEnc::Ver41xEnc(const char*& inBuffer) : inBuffer(inBuffer)
{
}

Ver41xEnc::~Ver41xEnc()
{
}

void Ver41xEnc::Process(char*& outBuffer)
{
	std::string testOutput = "Placeholder output buffer.";

	tempBuffer = new char[testOutput.length() + 1];
	strcpy(tempBuffer, testOutput.c_str());

	outBuffer = tempBuffer;
}
