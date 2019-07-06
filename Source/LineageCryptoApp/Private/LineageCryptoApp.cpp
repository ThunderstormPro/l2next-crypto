// L2EncDec.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "LineageCryptoApp.h"

using namespace LineageCryptoStreams;
using namespace LineageCryptoCommands;
/*
// TODO Just an usage example. Remove this.
class Custom41xStream : public DuplexStream
{
	virtual std::shared_ptr<std::iostream> Transform(const std::shared_ptr<std::iostream>& stream) override
	{
		auto transformed = std::make_shared<std::iostream>(this);
		std::vector<char> buffer;

		while (!stream->eof())
		{
			std::vector<char> chunk(8, 0);
			stream->read(chunk.data(), chunk.size());

			// TODO Modify chunk here. Remove this example :)
			// Replaces each first char in chunk with Z character.
			chunk.at(0) = 'Z';

			buffer.insert(buffer.end(), chunk.data(), chunk.data() + stream->gcount());
		}

		SetBuffer(buffer);

		return transformed;
	}
};*/

unique_ptr<LineageCryptoApp> LineageCryptoApp::getRef()
{
	return make_unique<LineageCryptoApp>();
}

void LineageCryptoApp::PrintIntro()
{
	cout << "# LineageCrypto.\n";
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
	auto app = LineageCryptoApp::getRef();

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
			//SFileStreamOptions options{ "D:/readable.dat", "D:/writable.dat" };
			/*
			auto input = StreamFactory::Make(ReadableStream(options));
			auto output = StreamFactory::Make(WritableStream(options));

			input
				->Pipe(StreamFactory::Make(Custom41xStream()))
				->Pipe(output);

			input->Bind_OnEnd([&](double duration) {
				printf("Time taken: %.2fs\n", duration);
			});

			input->Start();*/



		//	ifstream inStream(cp.src, ios::binary);
		//	ofstream outStream(cp.out, ios::binary);

			auto options = StreamFactory::Options(SFileStreamOptions{ cp.src, cp.out });
			auto command = LineageCrypto::Create<CDecrypt>(options);
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

			auto command = LineageCrypto::Create<CEncrypt>(
				inStream,
				outStream
			);

			LineageCrypto::Enqueue(command);
		}
	}

	LineageCrypto::OnPassed([&](L2Command& command) -> void {
		auto result = command.GetResult<SLineageFileSchema>();

		// TODO Cleanup
		switch (command.GetId())
		{
			case ECryptoCommands::ENCRYPT:
				cout << "Task for ENCRYPT command passed." << "\n";
				cout << "# Header  : " << result.header << "\n";
				cout << "# Version : " << result.version << "\n";

				if (result.buffer != nullptr)
				{
					cout << "# Buffer  : " << result.buffer << "\n";
				}

				break;
			case ECryptoCommands::DECRYPT:
				cout << "\nTask for DECRYPT command passed." << "\n";
				cout << "# Header  : " << result.header << "\n";
				cout << "# Version : " << result.version << "\n";

				if (result.buffer != nullptr)
				{
					cout << "# Buffer  : " << result.buffer << "\n";
				}

				break;
		}
	});

	LineageCrypto::OnFailed([&](L2Command& command) -> void {
		auto result = command.GetResult<SLineageFileSchema>();

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

	LineageCrypto::ExecuteAll();

	// Await user input.
	app->awaitClosing();
	
	// Cleanup.
	LineageCrypto::ReleaseAll();
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
