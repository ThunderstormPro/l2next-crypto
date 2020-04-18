#include "Utils/FileHelper.h"

std::string Utils::FileHelper::GetCurrentWorkingDirectory()
{
	char* Filename = new char[MAX_PATH];
	GetModuleFileNameA(NULL, Filename, MAX_PATH);

	char* LastDirectorySeparator = strrchr(Filename, '\\');
	*LastDirectorySeparator = '\0';

	return std::string(Filename);
}


SFileData Utils::FileHelper::ReadFromFile(std::string filepath) {
	std::ifstream file(filepath, std::ios::in | std::ios::binary);

	if (file)
	{
		std::string contents;
		file.seekg(0, std::ios::end);
		contents.resize(file.tellg());
		file.seekg(0, std::ios::beg);
		file.read(&contents[0], contents.size());
		file.close();
		return SFileData(contents);
	}
	throw(errno);

	return SFileData("");
}

bool Utils::FileHelper::WriteToFile(std::string filepath, SDecryptResult decryptedResult) {

	std::ofstream file(filepath, std::ios::out | std::ios::binary);

	if (file)
	{
		SFileData content = decryptedResult.content;

		file.write(content.GetData(), content.GetSize());
		file.close();

		return true;
	}
	throw(errno);

	return true;
}

bool Utils::FileHelper::WriteToFile(std::string filepath, SEncryptResult encryptedResult)
{
	return false;
}
