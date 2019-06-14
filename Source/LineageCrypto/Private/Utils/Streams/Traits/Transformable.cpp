#include "Utils/Streams/Traits/Transformable.h"

std::shared_ptr<std::iostream> TTransformable::Transform(const std::shared_ptr<std::iostream>& stream)
{
	return stream;
}
