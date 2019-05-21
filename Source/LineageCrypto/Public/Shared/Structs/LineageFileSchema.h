#ifndef H_LINEAGE_FILE_SCHEMA
#define H_LINEAGE_FILE_SCHEMA

#include <string>

using namespace std;

struct SLineageFileSchema
{
public:
	string status;
	string header;
	short version;
	char* buffer;
	string errorMsg;
};


#endif // H_LINEAGE_FILE_SCHEMA
