#ifndef H_LINEAGE_CRYPTO_APP
#define H_LINEAGE_CRYPTO_APP

#include "pch.h"
#include <string>
#include <iostream>
#include <functional>
#include <memory>
#include <typeinfo>

#include "L2NextCrypto.h"
#include "Utils/FileHelper.h"
#include "ConfigReader/ConfigReader.h"

class L2NextCryptoApp
{
public:
	static unique_ptr<L2NextCryptoApp> getRef();

	void PrintIntro();
	void PrintDecryptResult(std::string path, EDecryptErrorStatus error);
	void awaitClosing();

	void ReadCustomConfigPath();
	string GetConfigPath();

	const string defaultYamlConfig = "config\\config.yaml";
	string customYamlConfig = "";
	string ConfigPath = "";
};

#endif //H_LINEAGE_CRYPTO_APP
