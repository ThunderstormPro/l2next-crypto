#ifndef H_ENCRYPT
#define H_ENCRYPT

#include <fstream>
#include "TaskRunner/Interfaces/Command.h"

using namespace::std;

namespace LineageCryptoCommands
{
	class CEncrypt : public ICommand
	{
	public:
		CEncrypt(ifstream& inStream, ofstream& outStream);

		virtual bool Execute() override;

		~CEncrypt();
	};
}

#endif // H_ENCRYPT