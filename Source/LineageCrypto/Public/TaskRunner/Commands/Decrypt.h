#ifndef H_DECRYPT
#define H_DECRYPT

#include <fstream>
#include <iostream>
#include <functional>
#include <iterator>
#include <memory>
#include "Shared/Structs/LineageFileSchema.h"
#include "TaskRunner/Commands/BaseCommand.h"
#include "Shared/Enums/CryptoCommands.h"
#include "Crypto/Crypto.h"

using namespace::std;

namespace LineageCryptoCommands
{
	class CDecrypt: public BaseCommand
	{
	public:
		CDecrypt(ifstream& inStream, ofstream& outStream);
		~CDecrypt();

		virtual bool Execute() override;
	private:
		char* decryptBuffer;
		void ReadBuffer(ifstream& inStream);
	};
}

#endif // H_DECRYPT
