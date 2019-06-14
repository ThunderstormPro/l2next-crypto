#ifndef H_CONFIG_READER
#define H_CONFIG_READER

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Struct/ConfigBase.h"
#include "yaml-cpp/yaml.h"

using namespace std;

const string MSG_ERROR_LOAD_CONFIG = "-- Error message output: ";

class ConfigReader
{
// API
public:
	static unique_ptr<ConfigBase> TryLoadConfig(const string& path);
};

#endif //H_CONFIG_READER
