#include "Crypto/Algorithms/41x/Duplex/Ver41xDec.h"
#include <iostream>
#include <istream>
#include <streambuf>
#include <string>

Ver41xDec::Ver41xDec(Ver41xParams& params) : params(params)
{
}

Ver41xDec::~Ver41xDec()
{
}

void Ver41xDec::Transform(const char*& inBuffer, char*& outBuffer)
{
	


	/*std::string testOutput = "Placeholder output buffer.";

	container = new char[testOutput.length() + 1];
	strcpy(container, testOutput.c_str());

	outBuffer = container;*/
}