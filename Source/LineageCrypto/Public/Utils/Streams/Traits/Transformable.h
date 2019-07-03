#ifndef H_TRANSFORMABLE
#define H_TRANSFORMABLE

#include <memory>
#include "Utils/Streams/Traits/Streamable.h"

class TTransformable
	: public TStreamable
{

public:

	TTransformable()
	{

	}

protected:
	/** 
	* Override this method for custom transform implementation.
	* By default just returns the input stream passes to this method.
	*
	* @param const std::shared_ptr<std::iostream>& stream input stream.
	* @return std::shared_ptr<std::iostream> new stream or input stream.
	*/
	virtual std::shared_ptr<std::iostream> Transform(const std::shared_ptr<std::iostream>& stream);

};

#endif // H_TRANSFORMABLE
