#ifndef H_DECRYPT
#define H_DECRYPT

#include <fstream>
#include <iostream>
#include <functional>
#include <iterator>
#include <memory>
#include "Crypto/Crypto.h"
#include "Utils/Streams/Factory/StreamFactory.h"
#include "TaskRunner/Commands/BaseCommand.h"
#include "Shared/Enums/CryptoCommands.h"
#include "Shared/Structs/LineageFileSchema.h"
#include "Utils/Streams/Structs/BufStreamOptions.h"
#include "Utils/Streams/Structs/FileStreamOptions.h"

using namespace::std;
using namespace::LineageCryptoStreams;

namespace LineageCryptoCommands
{
	class CDecrypt: public BaseCommand
	{
	public:
		CDecrypt(std::shared_ptr<StreamOptions> options);
		~CDecrypt();

		virtual bool Execute() override;
		virtual void Release() override;
	private:
		void ReadStream(ifstream& inStream);

		std::shared_ptr<StreamOptions> _options;
	};
}

#endif // H_DECRYPT
