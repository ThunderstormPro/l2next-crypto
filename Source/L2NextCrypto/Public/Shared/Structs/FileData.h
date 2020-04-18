#ifndef H_FILE_DATA
#define H_FILE_DATA

#include <string>

struct SFileData {
	SFileData()
		: contents("") {}

	SFileData(const std::string contents)
		: contents(contents) {}

	const char* GetData() {
		return contents.c_str();
	}

	const size_t GetSize() {
		return contents.size();
	}

private:
	std::string contents;
};


#endif // H_FILE_DATA
