#include "Crypto/Validators/HeaderValidator/HeaderValidator.h"

HeaderValidator::HeaderValidator(const std::shared_ptr<std::iostream>& stream)
{
	headerString = ReadHeader(stream);
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

bool HeaderValidator::GetVersion(EHeaderVersion& versionRef)
{
	try {
		std::string versionString = headerString;
		versionString.erase(versionString.begin(), versionString.end() - LINEAGE_VERSION_LENGTH);

		const int version = std::stoi(versionString);

		if (IsVersionSupported(version))
		{
			versionRef = (EHeaderVersion&)version;
			return true;
		}

		versionRef = (EHeaderVersion&)version;
		return false;
	}
	catch (std::exception e)
	{
		versionRef = EHeaderVersion::INVALID;
		return false;
	}
}

std::string HeaderValidator::ReadHeader(const std::shared_ptr<std::iostream>& stream) const
{
	// Read stream to get the header.
	std::vector<char> header(LINEAGE_HEADER_SIZE, 0);
	stream->read(header.data(), header.size());

	// Transform it to plain string.
	std::string headerStr(header.data(), header.size());
	headerStr.erase(remove(headerStr.begin(), headerStr.end(), NULL_TERMINATOR_CHR), headerStr.end());
	return headerStr;
}

bool HeaderValidator::IsVersionSupported(const int & version)
{
	return AlgorithmRegistry::GetInstance().IsSupported(version);
}
