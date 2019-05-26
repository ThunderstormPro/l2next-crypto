#include "TaskRunner/Commands/Decrypt.h"

using namespace LineageCryptoCommands;

CDecrypt::CDecrypt(ifstream& inStream, ofstream& outStream)
{
	SetId(ECryptoCommands::DECRYPT);
	ReadBuffer(inStream);
}

bool CDecrypt::Execute()
{
	shared_ptr<SLineageFileSchema> x = make_shared<SLineageFileSchema>(Crypto::Decrypt(decryptBuffer));
	SetResult<SLineageFileSchema>(x);

	return true;
}

void CDecrypt::ReadBuffer(ifstream& inStream)
{
	decryptBuffer = new char(inStream.tellg());
	inStream.read(decryptBuffer, inStream.tellg());
}

CDecrypt::~CDecrypt()
{
}
