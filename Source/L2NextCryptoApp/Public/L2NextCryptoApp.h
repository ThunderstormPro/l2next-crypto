#ifndef H_LINEAGE_CRYPTO_APP
#define H_LINEAGE_CRYPTO_APP

#include "pch.h"
#include <string>
#include <sstream>
#include <functional>
#include <memory>
#include <typeinfo>

#include "L2NextCrypto.h"
#include "Utils/FileHelper.h"
#include "Utils/Logging.h"
#include "ConfigReader/ConfigReader.h"

class L2NextCryptoApp
{
public:
	static unique_ptr<L2NextCryptoApp> getRef();

	void awaitClosing();

	void ReadCustomConfigPath();
	std::string GetConfigPath();

	const std::string defaultYamlConfig = "config\\config.yaml";
	std::string customYamlConfig = "";
	std::string ConfigPath = "";
};

#endif //H_LINEAGE_CRYPTO_APP
