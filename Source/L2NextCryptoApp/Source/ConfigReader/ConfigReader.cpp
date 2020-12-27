#include "ConfigReader/ConfigReader.h"

std::unique_ptr<ConfigBase> ConfigReader::TryLoadConfig(const std::string& path)
{
	try
	{
		YAML::Node rootNode = YAML::LoadFile(path);

		std::unique_ptr<ConfigBase> config = std::make_unique<ConfigBase>();

		if (!rootNode["decrypt"] || !rootNode["encrypt"])
		{
			//Utils::Logging::PrintError("Decrypt or encrypt fields are missing in yaml config file.");
			return nullptr;
		}

		try 
		{
			config->Decrypt = rootNode["decrypt"].as<std::vector<ConfigPaths>>();
		}
		catch (std::exception e)
		{
			// ...
		}

		try
		{
			config->Encrypt = rootNode["encrypt"].as<std::vector<ConfigPaths>>();
		}
		catch (std::exception e)
		{
			// ...
		}

		Utils::Logging::PrintLog("Configuration file successfully loaded.");

		return config;
	}
	catch (const YAML::BadFile e)
	{
		//Utils::Logging::PrintError("Cannot load yaml config file.", e.msg);

		return nullptr;
	}
	catch (const YAML::ParserException e)
	{
		//Logging::PrintError("Cannot load yaml config file due to parsing error.", e.msg);
		
		return nullptr;
	}
}
