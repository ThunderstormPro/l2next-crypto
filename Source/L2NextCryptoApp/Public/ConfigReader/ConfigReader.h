#ifndef H_CONFIG_READER
#define H_CONFIG_READER

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Struct/ConfigBase.h"
#include "Utils/Logging.h"
#include "yaml-cpp/yaml.h"

class ConfigReader
{
public:
	static std::unique_ptr<ConfigBase> TryLoadConfig(const std::string& path);
};

#endif //H_CONFIG_READER
