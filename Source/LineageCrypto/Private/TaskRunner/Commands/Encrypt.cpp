#include "TaskRunner/Commands/Encrypt.h"
#include <iostream>

using namespace LineageCryptoCommands;

CEncrypt::CEncrypt(ifstream& inStream, ofstream& outStream)
{
	SetId(ECryptoCommands::ENCRYPT);
	ReadBuffer(inStream);
}

bool CEncrypt::Execute()
{
	shared_ptr<SLineageFileSchema> x = make_shared<SLineageFileSchema>(Crypto::Encrypt(encryptBuffer));
	SetResult<SLineageFileSchema>(x);

	return true;
}

void CEncrypt::ReadBuffer(ifstream& inStream)
{
	encryptBuffer = new char(inStream.tellg());
	inStream.read(encryptBuffer, inStream.tellg());
}

CEncrypt::~CEncrypt()
{
}
