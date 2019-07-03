#ifndef H_FILE_STREAM_OPTIONS
#define H_FILE_STREAM_OPTIONS

#include <string>
#include "StreamOptions.h"

struct SFileStreamOptions : public StreamOptions
{
public:
	SFileStreamOptions(std::string input, std::string output)
		: inputFile(input)
		, outputFile(output)
	{
	}

public:
	const char* GetInputFilePath()
	{
		return inputFile.c_str();
	};

	const char* GetOutputFilePath()
	{
		return outputFile.c_str();
	};

	virtual EStreamTypes GetType() final
	{
		return EStreamTypes::FILE;
	}

private:
	std::string inputFile;
	std::string outputFile;
};

#endif // H_FILE_STREAM_OPTIONS