#ifndef H_ALGORITHM_DUPLEX
#define H_ALGORITHM_DUPLEX

#include <memory>
#include <iostream>
#include "Crypto/Enums/CryptType.h"
#include "Crypto/Enums/HeaderVersion.h"
#include "Utils/Streams/Factory/StreamFactory.h"

using namespace::LineageCryptoStreams;

class AlgorithmDuplex : public DuplexStream
{
	virtual std::shared_ptr<std::iostream> Transform(const std::shared_ptr<std::iostream>& stream) final
	{
		auto transformed = std::make_shared<std::iostream>(this);

		std::vector<char> buffer;

		while (!stream->eof())
		{
			std::vector<char> chunk(8, 0);
			stream->read(chunk.data(), chunk.size());

			// TODO Modify chunk here. Remove this example :)
			// Replaces each first char in chunk with Z character.

			buffer.insert(buffer.end(), chunk.data(), chunk.data() + stream->gcount());
		}

		SetBuffer(buffer);

		return transformed;
	}
};

#endif // H_ALGORITHM_DUPLEX
