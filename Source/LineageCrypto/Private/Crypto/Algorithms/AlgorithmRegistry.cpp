#include "Crypto/Algorithms/AlgorithmRegistry.h"

AlgorithmRegistry::AlgorithmRegistry()
{
	Add<Ver411>();
	Add<Ver412>();
	Add<Ver413>();
	Add<Ver414>();
}

AlgorithmRegistry::~AlgorithmRegistry()
{
}

bool AlgorithmRegistry::IsSupported(const int& version)
{
	for (auto& algorithm : algorithms)
	{
		if (algorithm->GetVersion() == version)
		{
			return true;
		}
	}

	return false;
}

bool AlgorithmRegistry::Get(const int& version, Algorithm*& algorithm)
{
	for (auto& obj : algorithms)
	{
		if (obj->GetVersion() == version)
		{
			algorithm = obj.get();
			return true;
		}
	}

	return false;
}
