#include "Crypto/Algorithms/Base/Duplex/AlgorithmDuplex.h"

void AlgorithmDuplex::SetFileSchema(const SLineageFileSchema& _schema)
{
	schema = _schema;
}

std::shared_ptr<std::iostream> AlgorithmDuplex::Transform(const std::shared_ptr<std::iostream>& stream)
{
	Algorithm* algorithm = nullptr;

	if (!AlgorithmRegistry::GetInstance().Get(this->schema.version, algorithm))
	{
		Stop();
	}

	switch (schema.type)
	{
		case ECryptType::DEC:

			//const auto duplex = algorithm->GetDuplex().decrypt;

			//duplex->Transform(stream);

			//SDecryptResult result = s<SDecryptResult>(duplex->GetExecResult());

			//if (result.errorCode < 0)
			//{
			//	Exec_OnDecryptFailed(result);
			//}

			//const auto transformed = algorithm->GetDuplex().decrypt->Transform(stream);

			//if 

			return algorithm->GetDuplex().decrypt->Transform(stream);
		case ECryptType::ENC:
			return algorithm->GetDuplex().encrypt->Transform(stream);
		default:
			std::cout << "No explicit crypt type was provided." << std::endl;
			return std::make_shared<std::iostream>(this);
	}
}
