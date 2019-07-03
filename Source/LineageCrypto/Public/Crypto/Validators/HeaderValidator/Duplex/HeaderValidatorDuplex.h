#ifndef H_HEADER_VALIDATOR_DUPLEX
#define H_HEADER_VALIDATOR_DUPLEX

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <regex>
#include <iostream>
#include "Crypto/Algorithms/AlgorithmRegistry.h"
#include "Crypto/Algorithms/Base/Algorithm.h"
#include "Crypto/Enums/HeaderVersion.h"
#include "Utils/Streams/Factory/StreamFactory.h"

using namespace::LineageCryptoStreams;

class HeaderValidatorDuplex : public DuplexStream
{
	virtual std::shared_ptr<std::iostream> Transform(const std::shared_ptr<std::iostream>& stream) final
	{
		auto transformed = std::make_shared<std::iostream>(this);

		std::vector<char> buffer;

		std::vector<char> header(28, 0);
		stream->read(header.data(), header.size());

		std::cout << "HEADER::" << std::string(header.data(), header.size());

		buffer.insert(buffer.end(), header.begin(), header.end());

		while (!stream->eof())
		{
			std::vector<char> chunk(8, 0);
			stream->read(chunk.data(), chunk.size());

			buffer.insert(buffer.end(), chunk.data(), chunk.data() + stream->gcount());
		}

		SetBuffer(buffer);

		return transformed;
	}
};

#endif // H_HEADER_VALIDATOR_DUPLEX
