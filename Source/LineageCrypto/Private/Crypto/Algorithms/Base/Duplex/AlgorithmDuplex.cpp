#include "Crypto/Algorithms/Base/Duplex/AlgorithmDuplex.h"
#include "Crypto/Algorithms/AlgorithmRegistry.h"

std::shared_ptr<std::iostream> AlgorithmDuplex::Transform(const std::shared_ptr<std::iostream>& stream)
{
	Algorithm* algorithm = nullptr;

	if (!schema.version)
	{
		throw std::runtime_error("Required schema param: \"version\" is not passed to this duplex.");
	}

	if (!AlgorithmRegistry::GetInstance().Get(schema.version, algorithm))
	{
		schema.errorMsg = "Supported algorithm for this version could not be found.";
		Stop();
		return nullptr;
	}

	switch (schema.type)
	{
		case ECryptType::DEC:
			{
				// TODO revise this, use schema.
				const auto transformed = algorithm->GetDuplex().decrypt->Transform(stream);
				auto result = static_pointer_cast<SDecryptResult>(algorithm->GetDuplex().decrypt->GetExecResult());

				if (result->fileSize <= 0)
				{
					Exec_OnDecryptFailed(*result.get());
					return nullptr;
				}

				if (result)
				{
					schema.fileSize = result->fileSize;
					Exec_OnDecryptPassed(*result.get());
				}

				return transformed;
			}
		case ECryptType::ENC:
			// TODO Impl.
			return algorithm->GetDuplex().encrypt->Transform(stream);
		default:
			std::cout << "No explicit crypt type was provided." << std::endl;
			return nullptr;
	}
}
