#ifndef H_FILE_HELPER
#define H_FILE_HELPER

#include <string>
#include <iostream>
#include <fstream>
#include <iostream>
#include <Windows.h>

namespace Utils {
	class FileHelper {
	public:
		static std::string GetCurrentWorkingDirectory();
		static std::string GetFilenameFromPath(std::string path);
	};
}

#endif // H_FILE_HELPER