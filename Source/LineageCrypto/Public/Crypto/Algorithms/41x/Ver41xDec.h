#ifndef H_VER41XDEC
#define H_VER41XDEC

#include <string>

class Ver41xDec
{
public:
	Ver41xDec(const char*& inBuffer);
	~Ver41xDec();

public:
	void Process(char*& outBuffer);

private:
	const char*& inBuffer;
	char* tempBuffer;
};

#endif // H_VER41XDEC
