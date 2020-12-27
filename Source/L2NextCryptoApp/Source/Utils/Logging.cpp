#include "Utils/Logging.h"

void Utils::Logging::PrintLogo()
{
	std::printf(
		" _     ___  _  _            _     ___                   _         \n"
		"| |   |_  )| \\| | ___ __ __| |_  / __| _ _  _  _  _ __ | |_  ___  \n"
		"| |__  / / | .` |/ -_)\\ \\ /|  _|| (__ | '_|| || || '_ \\|  _|/ _ \\ \n"
		"|____|/___||_|\\_|\\___|/_\\_\\ \\__| \\___||_|   \\_, || .__/ \\__|\\___/ \n"
		"                                            |__/ |_|              \n"
	);
}

void Utils::Logging::PrintLog(std::string msg)
{
	std::printf("Log: %s \n", msg.c_str());
}

void Utils::Logging::PrintError(std::string msg, std::string reason)
{
	std::printf("Error: %s \n", msg.c_str());

	if (!reason.empty()) {
		std::printf("Reason: %s \n", reason.c_str());
	}
}

void Utils::Logging::PrintIntro()
{
	Utils::Logging::PrintLogo();

	std::printf("\n");

	std::printf(
		"# By default config.yaml located in config/config.yaml is used for enc/dec tasks.\n"
		"# If you want to specify a custom yaml config, type a `filename.yaml`, that is located relative to app directory.\n"
		"# Enter custom yaml config path, to skip just press ENTER:\n"
	);
}

void Utils::Logging::PrintConfigLoadStart()
{
	Utils::Logging::PrintLog("Loading yaml config file.");
}

void Utils::Logging::PrintDecryptStart(std::string path)
{
	Utils::Logging::PrintLog("File " + FileHelper::GetFilenameFromPath(path) + " decryption started.");
}


void Utils::Logging::PrintDecryptError(EDecryptError error)
{
	const std::string errorMsg = "File cannot be decrypted.";

	switch (error)
	{
	case EDecryptError::INVALID_HEADER:
		Utils::Logging::PrintError(errorMsg, "Input file has invalid header");
		break;
	case EDecryptError::VERSION_NOT_SUPPORTED:
		Utils::Logging::PrintError(errorMsg, "Header version is not supported");
		break;
	case EDecryptError::INFLATE_FAILED:
		Utils::Logging::PrintError(errorMsg, "ZLib inflate operation failed");
		break;
	}
}

void Utils::Logging::PrintDecryptSuccess()
{
	Utils::Logging::PrintLog("File successfully decrypted.");
}

void Utils::Logging::PrintFileError()
{
	Utils::Logging::PrintError("File not found or can't be read.");
}

void Utils::Logging::PrintSeparator()
{
	std::printf("-------------------------------------------------------------\n");
}

void Utils::Logging::PrintProgress(std::string heading, unsigned int current, unsigned int total)
{
	double percentage = (double)current / total;
	int val = (int)(percentage * 100);
	int lpad = (int)(percentage * PBWIDTH);
	int rpad = PBWIDTH - lpad;

	std::printf(
		"\rLog: %s - %3d%% [%.*s%*s].",
		heading.c_str(), val, lpad, PBSTR, rpad, ""
	);
	fflush(stdout);

	if (val == 100) {
		std::printf("\n");
	}
}