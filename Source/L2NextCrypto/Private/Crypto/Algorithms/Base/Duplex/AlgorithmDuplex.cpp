#include "Crypto/Algorithms/Base/Duplex/AlgorithmDuplex.h"
#include "Crypto/Algorithms/AlgorithmRegistry.h"

void AlgorithmDuplex::SetVersion(const int ver)
{
	version = ver;
}

std::stringstream& AlgorithmDuplex::Transform(std::stringstream& stream)
{
	Algorithm* algorithm = nullptr;

	if (!version)
	{
		throw std::runtime_error("Required param: \"version\" is not passed to this duplex.");
	}

	if (!AlgorithmRegistry::GetInstance().Get(version, algorithm))
	{
		Exec_OnDecryptFailed(version);
		return stream;
	}

	switch (type)
	{
	case ECryptType::DEC:
	{
		auto duplex = algorithm->GetDuplex().decrypt;
		return duplex->Transform(stream);
	}
	default:
		return stream;
	}
}