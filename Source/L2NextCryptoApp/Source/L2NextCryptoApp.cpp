#include "L2NextCryptoApp.h"

std::unique_ptr<L2NextCryptoApp> L2NextCryptoApp::getRef()
{
	return std::make_unique<L2NextCryptoApp>();
}

void L2NextCryptoApp::ReadCustomConfigPath()
{
	std::getline(std::cin, customYamlConfig);
}

std::string L2NextCryptoApp::GetConfigPath()
{
	return customYamlConfig.empty()
		? Utils::FileHelper::GetCurrentWorkingDirectory() + "\\" + defaultYamlConfig
		: Utils::FileHelper::GetCurrentWorkingDirectory() + "\\" + customYamlConfig;
}

void L2NextCryptoApp::awaitClosing()
{
	std::cout << "Press any key to exit program.";
	std::string await = "";
	std::getline(std::cin, await);
}

int main()
{
	auto app = L2NextCryptoApp::getRef();

	Utils::Logging::PrintIntro();
	app->ReadCustomConfigPath();

	Utils::Logging::PrintConfigLoadStart();
	auto config = ConfigReader::TryLoadConfig(app->GetConfigPath());

	if (config && !config->Decrypt.empty())
	{
		for (ConfigPaths cp : config->Decrypt)
		{
			Utils::Logging::PrintSeparator();

			std::ifstream input(cp.src, std::ios::binary);
			std::ofstream output(cp.out, std::ios::binary);

			if (input.is_open())
			{
				Utils::Logging::PrintDecryptStart(cp.src);

				try {
					std::stringstream stream;
					stream << input.rdbuf();
					 
					auto crypto = std::make_unique<L2NextCrypto>();

					crypto->OnDecryptChunk([&](const CryptoEvents::SDecryptedChunk& chunk) {
						Utils::Logging::PrintProgress("Decrypt", chunk.current, chunk.total);
					});

					crypto->OnInflateChunk([&](const CryptoEvents::SInflatedChunk& chunk) {
						Utils::Logging::PrintProgress("Inflate", chunk.current, chunk.total);
					});

					output << crypto->Decrypt(stream);

					Utils::Logging::PrintDecryptSuccess();
				}
				catch (EDecryptError err) {
					Utils::Logging::PrintDecryptError(err);
				}
			}
			else {
				Utils::Logging::PrintFileError();
			}

			input.close();
			output.close();

			Utils::Logging::PrintSeparator();
		}
	}

	app->awaitClosing();
	config.reset();
	app.reset();

	return 1;
}