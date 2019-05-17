#include "TaskRunner/Commands/Encrypt.h"
#include <iostream>

using namespace LineageCryptoCommands;

CEncrypt::CEncrypt(ifstream& inStream, ofstream& outStream)
{


}

bool CEncrypt::Execute()
{
	cout << "\nENCRYPT EXECUTING\n";

	// Fake encryption process.
	_sleep(2500);

	return true;
}

CEncrypt::~CEncrypt()
{
}
