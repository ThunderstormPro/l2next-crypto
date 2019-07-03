#ifndef H_VER41XENC
#define H_VER41XENC

#include <string>

class Ver41xEnc
{
public:
	Ver41xEnc(const char*& inBuffer);
	~Ver41xEnc();

public:
	void Process(char*& outBuffer);

private:
	const char*& inBuffer;
	char* tempBuffer = nullptr;
};

#endif // H_VER41XENC
