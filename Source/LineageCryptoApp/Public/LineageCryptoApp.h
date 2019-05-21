#ifndef H_LINEAGE_CRYPTO_APP
#define H_LINEAGE_CRYPTO_APP

#include "pch.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include <functional>
#include <memory>
#include <typeinfo>
#include "LineageCrypto.h"

#include "ConfigReader/ConfigReader.h"

using namespace std;

class LineageCryptoApp
{
public:
	/* Methods */
	static unique_ptr<LineageCryptoApp> getRef();

	void PrintIntro();
	void ReadCustomConfigPath();

	// TODO Extract to utils
	string GetCurrentWorkingDirectory();
	string GetConfigPath();

	void awaitClosing();

	/* Fields */
	const string defaultYamlConfig = "config\\config.yaml";
	string customYamlConfig = "";
	string ConfigPath = "";
};

#endif //H_LINEAGE_CRYPTO_APP
