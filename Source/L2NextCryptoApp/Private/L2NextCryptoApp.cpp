// L2EncDec.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "L2NextCryptoApp.h"

using namespace L2NextCryptoStreams;

unique_ptr<L2NextCryptoApp> L2NextCryptoApp::getRef()
{
	return make_unique<L2NextCryptoApp>();
}

void L2NextCryptoApp::PrintIntro()
{
	cout << "# L2NextCrypto.\n";
	cout << "# By default config.yaml located in config/config.yaml is used for enc/dec tasks.\n";
	cout << "# If you want to specify a custom yaml config, type a `filename.yaml`, that is located relative to app directory.\n";
	cout << "#\n";
	cout << "# Enter custom yaml config path, to skip just press ENTER:\n";
}

void L2NextCryptoApp::PrintDecryptResult(std::string path, EDecryptErrorStatus error) {

	const std::string filename = path.substr(path.find_last_of("/\\") + 1);

	if (error == EDecryptErrorStatus::NONE) {
		cout << "-------------------------------------------------------------" << std::endl;
		cout << "File decryption succeeded: " << filename << std::endl;
		cout << "-------------------------------------------------------------" << std::endl;

		return;
	}

	cout << "-------------------------------------------------------------" << std::endl;
	cout << "File decryption failed:" << filename << std::endl;

	switch (error)
	{
		case EDecryptErrorStatus::INVALID_HEADER:
			cout << "Reason: Input file has invalid header" << std::endl;
			break;
		case EDecryptErrorStatus::VERSION_NOT_SUPPORTED:
			cout << "Reason: Input file with this version is not supported" << std::endl;
			break;
		case EDecryptErrorStatus::INFLATE_FAILED:
			cout << "Reason: zlib inflate operation failed" << std::endl;
			break;
	}

	cout << "-------------------------------------------------------------" << std::endl;
}

string L2NextCryptoApp::GetCurrentWorkingDirectory()
{
	char* Filename = new char[MAX_PATH];
	GetModuleFileNameA(NULL, Filename, MAX_PATH);

	char* LastDirectorySeparator = strrchr(Filename, '\\');
	*LastDirectorySeparator = '\0';

	return string(Filename);
}

string L2NextCryptoApp::GetConfigPath()
{
	return customYamlConfig.empty() 
		? GetCurrentWorkingDirectory() + "\\" + defaultYamlConfig
		: GetCurrentWorkingDirectory() + "\\" + customYamlConfig;
}

void L2NextCryptoApp::ReadCustomConfigPath()
{
	getline(cin, customYamlConfig);
}

void L2NextCryptoApp::awaitClosing()
{
	cout << "Press any key to exit program.";
	string awaitClosing = "";
	getline(cin, awaitClosing);
}

int main()
{
	auto app = L2NextCryptoApp::getRef();

	app->PrintIntro();
	app->ReadCustomConfigPath();

	auto config = ConfigReader::TryLoadConfig(app->GetConfigPath());

	if (config == nullptr)
	{
		return 0;
	}

	if (!config->Decrypt.empty())
	{
		for (ConfigPaths cp : config->Decrypt)
		{
			try
			{
				auto encrypted = L2NextCryptoUtils::ReadFromFile(cp.src);
				auto decrypted = L2NextCrypto::Decrypt(encrypted);
				L2NextCryptoUtils::WriteToFile(cp.out, decrypted);

				app->PrintDecryptResult(cp.src, EDecryptErrorStatus::NONE);
				
			}
			catch (EDecryptErrorStatus error)
			{
				app->PrintDecryptResult(cp.src, error);
			}
		}
	}

	app->awaitClosing();
	config.reset();
	app.reset();

	return 1;
}