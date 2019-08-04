#ifndef H_DUPLEX_STREAM
#define H_DUPLEX_STREAM

#include <iostream>
#include <fstream>
#include <memory>
#include <streambuf>
#include "WritableStream.h"
#include "Traits/Transformable.h"
#include "Traits/Pipable.h"

namespace LineageCryptoStreams
{
	class DuplexStream
		: public TTransformable
		, public TPipable<DuplexStream, WritableStream>
	{
	public:
		using PipableTypes = TPipable<DuplexStream, WritableStream>;

		DuplexStream();
		DuplexStream(const DuplexStream& _self);
		~DuplexStream();

		void Exec(std::shared_ptr<std::iostream> stream) override;
	};
}

#endif // H_DUPLEX_STREAM
