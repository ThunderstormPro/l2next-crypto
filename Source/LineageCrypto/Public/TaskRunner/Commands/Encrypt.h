#ifndef H_ENCRYPT
#define H_ENCRYPT

#include <fstream>
#include <memory>
#include <functional>
#include "Crypto/Crypto.h"
#include "Shared/Structs/LineageFileSchema.h"
#include "TaskRunner/Commands/BaseCommand.h"

using namespace::std;

namespace LineageCryptoCommands
{
	class CEncrypt : public BaseCommand
	{
	public:
		CEncrypt(ifstream& inStream, ofstream& outStream);
		~CEncrypt();

		virtual bool Execute() override;
	private:
		char* encryptBuffer;
		void ReadBuffer(ifstream& inStream);
	};
}

#endif // H_ENCRYPT