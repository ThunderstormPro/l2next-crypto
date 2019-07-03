#ifndef H_INPUT_READER
#define H_INPUT_READER

#include <iostream>
#include <fstream>
#include <memory>
#include <streambuf>
#include "Utils/Streams/Traits/Writable.h"
#include "Utils/Streams/Structs/FileStreamOptions.h"
#include "Utils/Streams/Structs/BufStreamOptions.h"

namespace LineageCryptoStreams {

	class WritableStream
		: public TWritable
	{
	public:
		WritableStream(const WritableStream& _self)
			: options(_self.options)
		{
		};


		WritableStream(StreamOptions& options)
			: options(options)
		{
		};

	public:
		virtual void Exec(std::shared_ptr<std::iostream> stream) final;

	private:
		StreamOptions& options;
	};
}
#endif
