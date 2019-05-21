// L2EncDec.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "LineageCryptoApp.h"

using namespace LineageCryptoCommands;

unique_ptr<LineageCryptoApp> LineageCryptoApp::getRef()
{
	return make_unique<LineageCryptoApp>();
}

void LineageCryptoApp::PrintIntro()
{
	cout << "# LineageCrypto.";
	cout << "# By default config.yaml located in config/config.yaml is used for enc/dec tasks.\n";
	cout << "# If you want to specify a custom yaml config, type a `filename.yaml`, that is located relative to app directory.\n";
	cout << "#\n";
	cout << "# Enter custom yaml config path, to skip just press ENTER:\n";
}

string LineageCryptoApp::GetCurrentWorkingDirectory()
{
	char* Filename = new char[MAX_PATH];
	GetModuleFileNameA(NULL, Filename, MAX_PATH);

	char* LastDirectorySeparator = strrchr(Filename, '\\');
	*LastDirectorySeparator = '\0';

	return string(Filename);
}

string LineageCryptoApp::GetConfigPath()
{
	return customYamlConfig.empty() 
		? GetCurrentWorkingDirectory() + "\\" + defaultYamlConfig
		: GetCurrentWorkingDirectory() + "\\" + customYamlConfig;
}

void LineageCryptoApp::ReadCustomConfigPath()
{
	// Read custom config path.
	getline(cin, customYamlConfig);
}

void LineageCryptoApp::awaitClosing()
{
	cout << "Press any key to exit program.";
	string awaitClosing = "";
	getline(cin, awaitClosing);
}

int main()
{
	auto& app = LineageCryptoApp::getRef();

	// Print intro.
	app->PrintIntro();

	// Wait for user input.
	app->ReadCustomConfigPath();

	// Try to load yaml config file.
	auto& config = ConfigReader::TryLoadConfig(app->GetConfigPath());

	if (config == nullptr) 
	{
		return 0;
	}
	
	// Decrypt task.
	if (!config->Decrypt.empty())
	{
		for (ConfigPaths cp : config->Decrypt)
		{
			ifstream inStream(cp.src, ios::binary);
			ofstream outStream(cp.out, ofstream::binary);
			
			CDecrypt command(
				inStream,
				outStream
			);

			LineageCrypto::Enqueue(command);
		}
	}

	// Encrypt task.
	if (!config->Encrypt.empty())
	{
		for (ConfigPaths cp : config->Encrypt)
		{
			ifstream inStream(cp.src, ios::binary);
			ofstream outStream(cp.out, ofstream::binary);

			CEncrypt command(
				inStream,
				outStream
			);

			LineageCrypto::Enqueue(command);
		}
	}

	LineageCrypto::OnPassed([](ICommand& cmnd) -> void {
		// Task passed with command `cmnd`.
	});

	LineageCrypto::OnFailed([](ICommand& cmnd) -> void {
		// Task failed with command `cmnd`.
	});

	LineageCrypto::ExecuteAll();

	// Await user input.
	app->AwaitClosing();
	
	// Cleanup.
	LineageCrypto::Release();
	config.reset();
	app.reset();

	return 1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
