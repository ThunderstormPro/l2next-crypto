#ifndef H_LINEAGE_FILE_SCHEMA
#define H_LINEAGE_FILE_SCHEMA

#include <string>
#include "Crypto/Enums/HeaderVersion.h"
#include "Crypto/Enums/CryptType.h"

using namespace std;

struct SLineageFileSchema
{
public:
	ECryptType type;
	string header;
	EHeaderVersion version;
	char* buffer = nullptr;
	string errorMsg;
};


#endif // H_LINEAGE_FILE_SCHEMA
