#ifndef H_CONFIG_BASE
#define H_CONFIG_BASE

#include <string>
#include <vector>
#include "ConfigPaths.h"

using namespace std;

struct ConfigBase
{
public:
	//ConfigPaths*
	vector<ConfigPaths> Decrypt;
	vector<ConfigPaths> Encrypt;
};

#endif //H_CONFIG_BASE
