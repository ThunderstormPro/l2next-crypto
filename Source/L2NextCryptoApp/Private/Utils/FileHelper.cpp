#include "Utils/FileHelper.h"

std::string Utils::FileHelper::GetCurrentWorkingDirectory()
{
	char* Filename = new char[MAX_PATH];
	GetModuleFileNameA(NULL, Filename, MAX_PATH);

	char* LastDirectorySeparator = strrchr(Filename, '\\');
	*LastDirectorySeparator = '\0';

	return std::string(Filename);
}

std::string Utils::FileHelper::GetFilenameFromPath(std::string path)
{
	return path.substr(path.find_last_of("/\\") + 1);
}
