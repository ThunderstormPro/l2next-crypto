#include "TaskRunner/Commands/Encrypt.h"

using namespace LineageCryptoCommands;

CEncrypt::CEncrypt(ifstream& inStream, ofstream& outStream)
{
	SetId(ECryptoCommands::ENCRYPT);
	ReadStream(inStream);
}

bool CEncrypt::Execute()
{
	shared_ptr<SLineageFileSchema> schema = make_shared<SLineageFileSchema>(Crypto::Encrypt(encryptBuffer));
	SetResult<SLineageFileSchema>(schema);

	return schema->errorMsg.empty() ? true : false;
}

void CEncrypt::Release()
{
	encryptBuffer = nullptr;
	delete encryptBuffer;
}

void CEncrypt::ReadStream(ifstream& inStream)
{
	// Get length of file.
	inStream.seekg(0, inStream.end);
	int length = inStream.tellg();
	inStream.seekg(0, inStream.beg);

	// Read file contents to buffer.
	encryptBuffer = new char[length];
	inStream.read(encryptBuffer, length);

	// Close stream.
	inStream.clear();
	inStream.close();
}

CEncrypt::~CEncrypt()
{
}
