#ifndef H_LINEAGE_HEADER
#define H_LINEAGE_HEADER

#include <string>
#include <memory>
#include <regex>
#include "Crypto/Enums/HeaderVersion.h"
#include "Utils/Streams/Factory/StreamFactory.h"

const char NULL_TERMINATOR_CHR = '\0';
const char LINEAGE_HEADER_SIZE = 28;
const char LINEAGE_VERSION_LENGTH = 3;
const short LINEAGE_VERSION_MIN_DIGITS = 100;
const std::regex LINEAGE_HEADER_SIGNATURE = std::regex("^Lineage2Ver\\d{3}$");
const std::string INVALID_HEADER_SIGNATURE = "INVALID_HEADER_SIGNATURE";

class HeaderValidator
{

public:
	HeaderValidator(const std::shared_ptr<std::iostream>& stream);

	/**
	 * Get header string.
	 *
	 * @param headerRef headerRef pass result header.
	 * @return bool success status.
	 */
	bool GetHeader(std::string& headerRef) const;

	/** 
	 * Get header version.
	 *
	 * @param versionRef pass supported version. Returns -1 if is not supported or could not be parsed.
	 * @return bool success status.
	 */
	bool GetVersion(EHeaderVersion& versionRef);

	/**
	 * Gets header string from buffer.
	 *
	 * @param stream input stream to get header from.
	 * @return string retrieved header.
	 */
	std::string ReadHeader(const std::shared_ptr<std::iostream>& stream) const;

	/**
	 * Check if version has more then 3 digits and is supported by lib.
	 *
	 * @param version version to check.
	 * @return bool is supported or not.
	 */
	static bool IsVersionSupported(const int& version);

private:
	std::string headerString;
};

#endif // H_LINEAGE_HEADER
