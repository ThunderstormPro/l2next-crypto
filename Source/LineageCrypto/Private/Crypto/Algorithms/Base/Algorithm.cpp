#include "Crypto/Algorithms/Base/Algorithm.h"

const DuplexTypes& Algorithm::GetDuplex() const
{
	return duplex;
}

EHeaderVersion Algorithm::GetVersion() const
{
	return version;
}