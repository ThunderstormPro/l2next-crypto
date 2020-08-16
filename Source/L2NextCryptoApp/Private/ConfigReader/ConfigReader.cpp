#include "ConfigReader/ConfigReader.h"

using namespace YAML;
using namespace Utils;

unique_ptr<ConfigBase> ConfigReader::TryLoadConfig(const string& path)
{
	try
	{
		Node rootNode = LoadFile(path);

		unique_ptr<ConfigBase> config = make_unique<ConfigBase>();

		if (!rootNode["decrypt"] || !rootNode["encrypt"])
		{
			Logging::PrintError("Decrypt or encrypt fields are missing in yaml config file.");
			return nullptr;
		}

		try 
		{
			config->Decrypt = rootNode["decrypt"].as<vector<ConfigPaths>>();
		}
		catch (exception e)
		{
			// ...
		}

		try
		{
			config->Encrypt = rootNode["encrypt"].as<vector<ConfigPaths>>();
		}
		catch (exception e)
		{
			// ...
		}

		Logging::PrintLog("Configuration file successfully loaded.");

		return config;
	}
	catch (const BadFile e)
	{
		Logging::PrintError("Cannot load yaml config file.", e.msg);

		return nullptr;
	}
	catch (const ParserException e)
	{
		Logging::PrintError("Cannot load yaml config file due to parsing error.", e.msg);
		
		return nullptr;
	}
}
