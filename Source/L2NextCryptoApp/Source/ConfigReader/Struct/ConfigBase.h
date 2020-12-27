#ifndef H_CONFIG_BASE
#define H_CONFIG_BASE

#include <string>
#include <vector>
#include "ConfigPaths.h"

struct ConfigBase
{
public:
	//ConfigPaths*
	std::vector<ConfigPaths> Decrypt;
	std::vector<ConfigPaths> Encrypt;
};

#endif //H_CONFIG_BASE
