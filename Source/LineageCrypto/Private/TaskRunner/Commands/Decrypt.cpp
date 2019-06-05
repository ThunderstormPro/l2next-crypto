#include "TaskRunner/Commands/Decrypt.h"

using namespace LineageCryptoCommands;

CDecrypt::CDecrypt(ifstream& inStream, ofstream& outStream)
{
	SetId(ECryptoCommands::DECRYPT);
	ReadStream(inStream);
}

bool CDecrypt::Execute()
{
	shared_ptr<SLineageFileSchema> schema = make_shared<SLineageFileSchema>(Crypto::Decrypt(buffer));
	SetResult<SLineageFileSchema>(schema);

	return schema->errorMsg.empty() ? true : false;
}

void CDecrypt::Release()
{
	buffer = nullptr;
	delete buffer;
}

void CDecrypt::ReadStream(ifstream& inStream)
{
	// Get length of file.
	inStream.seekg(0, inStream.end);
	bufferSize = inStream.tellg();
	inStream.seekg(0, inStream.beg);

	// Read file contents to buffer.
	buffer = new char[bufferSize];
	inStream.read(buffer, bufferSize);

	// Close stream.
	inStream.clear();
	inStream.close();
}

CDecrypt::~CDecrypt()
{

}
