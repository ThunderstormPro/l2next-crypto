#include "ConfigReader/ConfigReader.h"

using namespace YAML;

unique_ptr<ConfigBase> ConfigReader::TryLoadConfig(string& path)
{
	try
	{
		Node rootNode = LoadFile(path);

		unique_ptr<ConfigBase> config = make_unique<ConfigBase>();

		if (!rootNode["decrypt"] || !rootNode["encrypt"])
		{
			cout << "Decrypt or encrypt fields are missing in yaml config file.";
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

		cout << "-- Configuration file succesfully loaded.\n";

		return config;
	}
	catch (const BadFile e)
	{
		cout << "-- Cannot load yaml config file: " + path + ".\n";
		cout << "-- File with the given path was not find.\n";
		cout << MSG_ERROR_LOAD_CONFIG + e.msg + "\n";

		return nullptr;
	}
	catch (const ParserException e)
	{
		cout << "-- Cannot load yaml config file due to parsing error. Check the syntax of your yaml config file.\n";
		cout << MSG_ERROR_LOAD_CONFIG + e.msg + "\n";

		return nullptr;
	}
}
