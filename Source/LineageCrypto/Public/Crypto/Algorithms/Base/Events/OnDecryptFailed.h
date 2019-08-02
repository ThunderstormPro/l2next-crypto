#ifndef H_ALGORITHM_DUPLEX
#define H_ALGORITHM_DUPLEX

#include <memory>
#include <iostream>
#include "Crypto/Enums/CryptType.h"
#include "Crypto/Enums/HeaderVersion.h"
#include "Crypto/Algorithms/Base/Algorithm.h"
#include "Crypto/Algorithms/AlgorithmRegistry.h"
#include "Utils/Streams/Factory/StreamFactory.h"
#include "Shared/Structs/LineageFileSchema.h"

using namespace::LineageCryptoStreams;

class AlgorithmDuplex : public DuplexStream
{
public:
	void SetFileSchema(SLineageFileSchema schema)
	{
		_schema = schema;
	}
private:
	SLineageFileSchema _schema;

	virtual std::shared_ptr<std::iostream> Transform(const std::shared_ptr<std::iostream>& stream) final
	{
		Algorithm* algorithm = nullptr;
		
		if (!AlgorithmRegistry::GetInstance().Get(_schema.version, algorithm))
		{
			Stop();
		}

		switch (_schema.type)
		{
			case ECryptType::DEC:
				return algorithm->GetDuplex().decrypt->Transform(stream);
			case ECryptType::ENC:
				return algorithm->GetDuplex().encrypt->Transform(stream);
			default:
				std::cout << "No explicit crypt type was provided." << std::endl;
				return std::make_shared<std::iostream>(this);
		}
	}
};

#endif // H_ALGORITHM_DUPLEX
