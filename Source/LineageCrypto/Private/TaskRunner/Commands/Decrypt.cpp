#include "TaskRunner/Commands/Decrypt.h"


using namespace LineageCryptoCommands;

CDecrypt::CDecrypt(ifstream& inStream, ofstream& outStream)
{

}


bool CDecrypt::Execute()
{
	cout << "\nDECRYPT EXECUTING\n";

	// Fake decryption process.
	_sleep(2500);

	return true;
}

CDecrypt::~CDecrypt()
{
}
