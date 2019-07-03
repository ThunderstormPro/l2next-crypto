#include "TaskRunner/Commands/Decrypt.h"

using namespace LineageCryptoCommands;

CDecrypt::CDecrypt(ifstream& inStream, ofstream& outStream)
{
	SetId(ECryptoCommands::DECRYPT);
	ReadStream(inStream);
}

bool CDecrypt::Execute()
{
	shared_ptr<SLineageFileSchema> schema = make_shared<SLineageFileSchema>(Crypto::Decrypt(decryptBuffer));
	SetResult<SLineageFileSchema>(schema);

	return schema->errorMsg.empty() ? true : false;
}

void CDecrypt::Release()
{
	decryptBuffer = nullptr;
	delete decryptBuffer;
}

void CDecrypt::ReadStream(ifstream& inStream)
{
	// Get length of file.
	inStream.seekg(0, inStream.end);
	int length = inStream.tellg();
	inStream.seekg(0, inStream.beg);

	// Read file contents to buffer.
	decryptBuffer = new char[length];
	inStream.read(decryptBuffer, length);

	// Close stream.
	inStream.clear();
	inStream.close();
}

CDecrypt::~CDecrypt()
{

}
