#ifndef H_LINEAGE_CRYPTO_APP
#define H_LINEAGE_CRYPTO_APP

#include "pch.h"
#include <string> 
#include <iostream>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include "LineageCrypto.h"
#include "ConfigReader/ConfigReader.h"

using namespace std;

class LineageCryptoApp
{
	// Define variables.
	const string defaultYamlConfig = "config\\config.yaml";
	string customYamlConfig = "";
	string ConfigPath = "";

/* Methods */
public:
	void PrintIntro();
	void ReadCustomConfigPath();

	// TODO Extract to utils
	string GetCurrentWorkingDirectory();
	string GetConfigPath();
};

#endif //H_LINEAGE_CRYPTO_APP
