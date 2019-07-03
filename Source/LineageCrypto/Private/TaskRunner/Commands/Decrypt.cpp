#include "TaskRunner/Commands/Decrypt.h"

using namespace LineageCryptoCommands;
using namespace LineageCryptoStreams;

CDecrypt::CDecrypt(std::shared_ptr<StreamOptions> options)
	: _options(options)
{
	SetId(ECryptoCommands::DECRYPT);
}

bool CDecrypt::Execute()
{
	auto input = StreamFactory::Make(ReadableStream(*_options.get()));
	auto output = StreamFactory::Make(WritableStream(*_options.get()));

	auto schema = std::make_shared<SLineageFileSchema>(Crypto::Decrypt(input, output));
	SetResult<SLineageFileSchema>(schema);

	return schema->errorMsg.empty() ? true : false;
}

void CDecrypt::Release()
{
	//buffer = nullptr;
	//delete buffer;
}

void CDecrypt::ReadStream(ifstream& inStream)
{
	// Get length of file.
	//inStream.seekg(0, inStream.end);
//	bufferSize = inStream.tellg();
	//inStream.seekg(0, inStream.beg);

	// Read file contents to buffer.
	//buffer = new char[bufferSize];
	//inStream.read(buffer, bufferSize);

	// Close stream.
//	inStream.clear();
	//inStream.close();
}

CDecrypt::~CDecrypt()
{

}
