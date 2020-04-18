#ifndef H_FILE_HELPER
#define H_FILE_HELPER

#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Shared/Structs/FileData.h"
#include "Crypto/Structs/DecryptResult.h"
#include "Crypto/Structs/EncryptResult.h"


namespace Utils {
	class FileHelper {
	public:
		static SFileData ReadFromFile(std::string filepath);
		static bool WriteToFile(std::string filepath, SDecryptResult decryptedResult);
		static bool WriteToFile(std::string filepath, SEncryptResult encryptedResult);

		static std::string GetCurrentWorkingDirectory();
	};
}

#endif // H_FILE_HELPER