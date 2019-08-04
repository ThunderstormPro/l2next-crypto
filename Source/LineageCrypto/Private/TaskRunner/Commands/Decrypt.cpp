#include <utility>
#include "TaskRunner/Commands/Decrypt.h"

using namespace LineageCryptoCommands;
using namespace LineageCryptoStreams;

CDecrypt::CDecrypt(std::shared_ptr<StreamOptions> options)
	: options(std::move(options))
{
	SetId(DECRYPT);
}

bool CDecrypt::Execute()
{
	const auto input = StreamFactory::Make(ReadableStream(*options.get()));
	const auto output = StreamFactory::Make(WritableStream(*options.get()));

	const auto schema = std::make_shared<SLineageFileSchema>(Crypto::Decrypt(input, output));
	SetResult<SLineageFileSchema>(schema);

	return schema->errorMsg.empty();
}

void CDecrypt::Release()
{
	options.reset();
}
