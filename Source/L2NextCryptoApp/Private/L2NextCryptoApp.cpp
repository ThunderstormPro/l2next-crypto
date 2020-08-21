#include "L2NextCryptoApp.h"

using namespace L2NextCryptoStreams;
using namespace Utils;

unique_ptr<L2NextCryptoApp> L2NextCryptoApp::getRef()
{
	return make_unique<L2NextCryptoApp>();
}

void L2NextCryptoApp::ReadCustomConfigPath()
{
	getline(cin, customYamlConfig);
}

std::string L2NextCryptoApp::GetConfigPath()
{
	return customYamlConfig.empty()
		? FileHelper::GetCurrentWorkingDirectory() + "\\" + defaultYamlConfig
		: FileHelper::GetCurrentWorkingDirectory() + "\\" + customYamlConfig;
}

void L2NextCryptoApp::awaitClosing()
{
	cout << "Press any key to exit program.";
	std::string await = "";
	getline(cin, await);
}

int main()
{
	auto app = L2NextCryptoApp::getRef();

	Logging::PrintIntro();
	app->ReadCustomConfigPath();

	Logging::PrintConfigLoadStart();
	auto config = ConfigReader::TryLoadConfig(app->GetConfigPath());

	if (config && !config->Decrypt.empty())
	{
		for (ConfigPaths cp : config->Decrypt)
		{
			Logging::PrintSeparator();

			std::ifstream input(cp.src, std::ios::binary);
			std::ofstream output(cp.out, std::ios::binary);

			if (input.is_open())
			{
				Logging::PrintDecryptStart(cp.src);

				try {
					std::stringstream stream;
					stream << input.rdbuf();

					auto crypto = std::make_unique<L2NextCrypto>();

					crypto->OnDecryptChunk([&](const SDecryptedChunk& chunk) {
						Logging::PrintProgress("Decrypt", chunk.current, chunk.total);
					});

					crypto->OnInflateChunk([&](const SInflatedChunk& chunk) {
						Logging::PrintProgress("Inflate", chunk.current, chunk.total);
					});

					output << crypto->Decrypt(stream);

					Logging::PrintDecryptSuccess();
				}
				catch (EDecryptError err) {
					Logging::PrintDecryptError(err);
				}
			}
			else {
				Logging::PrintFileError();
			}

			input.close();
			output.close();

			Logging::PrintSeparator();
		}
	}

	app->awaitClosing();
	config.reset();
	app.reset();

	return 1;
}