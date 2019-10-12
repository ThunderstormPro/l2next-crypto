// L2EncDec.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "L2NextCryptoApp.h"

using namespace L2NextCryptoStreams;
using namespace L2NextCryptoCommands;

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
	// Read custom config path.
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

	// Print intro.
	app->PrintIntro();

	// Wait for user input.
	app->ReadCustomConfigPath();

	// Try to load yaml config file.
	auto config = ConfigReader::TryLoadConfig(app->GetConfigPath());

	if (config == nullptr)
	{
		return 0;
	}

	// Decrypt task.
	if (!config->Decrypt.empty())
	{
		for (ConfigPaths cp : config->Decrypt)
		{
			const auto options = StreamFactory::Options(SFileStreamOptions{ cp.src, cp.out });
			auto command = L2NextCrypto::Create<CDecrypt>(options);
			L2NextCrypto::Enqueue(command);
		}
	}

	// Encrypt task.
	if (!config->Encrypt.empty())
	{
		for (ConfigPaths cp : config->Encrypt)
		{
			ifstream inStream(cp.src, ios::binary);
			ofstream outStream(cp.out, ofstream::binary);

			auto command = L2NextCrypto::Create<CEncrypt>(
				inStream,
				outStream
			);

			L2NextCrypto::Enqueue(command);
		}
	}

	L2NextCrypto::OnPassed([&](L2Command& command) -> void {
		const auto result = command.GetResult<SLineageFileSchema>();

		// TODO Cleanup
		switch (command.GetId())
		{
			case ECryptoCommands::ENCRYPT:
				cout << "Task for ENCRYPT command passed." << "\n";
				cout << "# Header  : " << result.header << "\n";
				cout << "# Version : " << result.version << "\n";
				break;
			case ECryptoCommands::DECRYPT:
				cout << "\nTask for DECRYPT command passed." << "\n";
				cout << "# Header  : " << result.header << "\n";
				cout << "# Version : " << result.version << "\n";
				cout << "# Output file size : " << result.fileSize << "\n";
				break;
		}
	});

	L2NextCrypto::OnFailed([&](L2Command& command) -> void {
		const auto result = command.GetResult<SLineageFileSchema>();

		switch (command.GetId())
		{
			case ECryptoCommands::ENCRYPT:
				cout << "Task for ENCRYPT command failed." << "\n";
				cout << "# Version  : " << result.version << "\n";
				cout << "# Error   : " << result.errorMsg << "\n";
				break;
			case ECryptoCommands::DECRYPT:
				cout << "\nTask for DECRYPT command failed." << "\n";
				cout << "# Version  : " << result.version << "\n";
				cout << "# Error   : " << result.errorMsg << "\n";
				break;
		}
	});

	L2NextCrypto::ExecuteAll();

	// Await user input.
	app->awaitClosing();
	
	// Cleanup.
	L2NextCrypto::ReleaseAll();
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
