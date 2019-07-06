#ifndef H_VER41XDEC
#define H_VER41XDEC

#include <iostream>
#include <algorithm>
#include <istream>
#include <streambuf>
#include <string>
#include "gmp.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include "zlib.h"
#include "Crypto/Algorithms/41x/Shared/Ver41xParams.h"
#include "Utils/Streams/Factory/StreamFactory.h"

#define BLOCK_SIZE 128

using namespace::LineageCryptoStreams;

class Ver41xDecDuplex : public DuplexStream
{
public:
	Ver41xDecDuplex(Ver41xParams& params);
	~Ver41xDecDuplex();

public:
	virtual std::shared_ptr<std::iostream> Transform(const std::shared_ptr<std::iostream>& stream) final;

private:
	int GetAvailableReadBytes();
	bool EnsureFilled(const std::shared_ptr<std::iostream>& stream);

	Ver41xParams params;
	std::vector<char> buffer = std::vector<char>(BLOCK_SIZE, 0);
	int decBuffer[32]{ 0 };

	int position = 0;
	int startPosition = 0;
	int size = 0;
	int unpackedSize = 0;

	// Initialize Decrypt buffer.
	size_t count = 32;

	mpz_t modulus, readBlock, modPowedBlock;
};

#endif // H_VER41XDEC
