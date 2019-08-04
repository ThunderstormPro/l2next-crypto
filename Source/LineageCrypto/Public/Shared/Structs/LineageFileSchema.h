#ifndef H_LINEAGE_FILE_SCHEMA
#define H_LINEAGE_FILE_SCHEMA

#include <string>
#include "Crypto/Enums/HeaderVersion.h"
#include "Crypto/Enums/CryptType.h"
#include <string>

using namespace std;

struct SLineageFileSchema
{
	ECryptType type;
	std::string header;
	EHeaderVersion version;
	size_t fileSize;
	char* buffer;
	std::string errorMsg;

	SLineageFileSchema()
	{
		type = ECryptType::ENC;
		header = "none";
		version = NOT_IMPL;
		fileSize = 0;
		buffer = nullptr;
		errorMsg = "none";
	}
};


#endif // H_LINEAGE_FILE_SCHEMA
