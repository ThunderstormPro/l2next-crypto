#ifndef H_DECRYPT
#define H_DECRYPT

#include <fstream>
#include <iostream>
#include <functional>
#include "TaskRunner/Interfaces/Command.h"
#include "TaskRunner/Delegates/CommandEvents.h"


using namespace::std;

namespace LineageCryptoCommands
{
	class CDecrypt: public ICommand
	{
	public:
		CDecrypt(ifstream& inStream, ofstream& outStream);

		virtual bool Execute() override;

		~CDecrypt();
	};
}

#endif // H_DECRYPT