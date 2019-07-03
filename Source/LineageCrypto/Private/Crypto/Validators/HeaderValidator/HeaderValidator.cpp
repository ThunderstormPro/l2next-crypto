#include "Crypto/Validators/HeaderValidator.h"

HeaderValidator::HeaderValidator(const char*& buffer)
{
	headerString = ReadHeader(buffer);
}

bool HeaderValidator::GetHeader(std::string& headerRef) const 
{
	if (!regex_search(headerString.c_str(), LINEAGE_HEADER_SIGNATURE))
	{
		headerRef = INVALID_HEADER_SIGNATURE;
		return false;
	}

	headerRef = headerString;
	return true;
}

bool HeaderValidator::GetVersion(int& versionRef)
{
	try {
		std::string versionString = headerString;
		versionString.erase(versionString.begin(), versionString.end() - LINEAGE_VERSION_LENGTH);

		const int version = std::stoi(versionString);

		if (IsVersionSupported(version))
		{
			versionRef = version;
			return true;
		}

		versionRef = EHeaderVersion::NOT_IMPL;
		return false;
	}
	catch (std::exception e)
	{
		versionRef = EHeaderVersion::INVALID;
		return false;
	}
}

std::string HeaderValidator::ReadHeader(const char *& buffer) const
{
	std::string header(buffer, LINEAGE_HEADER_SIZE);
	header.erase(remove(header.begin(), header.end(), NULL_TERMINATOR_CHR), header.end());
	return header;
}

bool HeaderValidator::IsVersionSupported(const int & version)
{
	return AlgorithmRegistry::GetInstance().IsSupported(version);
}
