#ifndef H_LOGGING
#define H_LOGGING

#include <string>
#include <iostream>
#include <cstdio>
#include "FileHelper.h"
#include "L2NextCrypto.h"


namespace Utils {
	class Logging {
	public:
		static void PrintIntro();
		static void PrintConfigLoadStart();
		static void PrintDecryptStart(std::string path);
		static void PrintDecryptError(EDecryptError error);
		static void PrintDecryptSuccess();
		static void PrintFileError();
		static void PrintSeparator();
		static void PrintLog(std::string msg);
		static void PrintError(std::string msg, std::string reason = "");
	};
}

#endif // H_LOGGING