#include "Crypto/Algorithms/41x/Duplex/Ver41xDecDuplex.h"
#include <iostream>
#include <istream>
#include <streambuf>
#include <string>

Ver41xDec::Ver41xDec(Ver41xParams& params) : params(params)
{
}

Ver41xDec::~Ver41xDec()
{
}

std::shared_ptr<std::iostream> Ver41xDec::Transform(const std::shared_ptr<std::iostream>& stream)
{
	return std::shared_ptr<std::iostream>();
}