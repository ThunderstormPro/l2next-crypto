#include "Utils/Streams/Traits/Streamable.h"

void TStreamable::Propagate(TStreamable* pipe, std::shared_ptr<std::iostream> stream)
{
	if (pipe != nullptr && bIsStreaming)
	{
		pipe->Exec(stream);
	}
}

void TStreamable::Start()
{
	if (!bIsStreaming)
	{
		bIsStreaming = true;
		Exec(std::make_shared<std::iostream>(this));
	}
}
void TStreamable::Stop()
{
	bIsStreaming = false;
}

void TStreamable::SetBuffer(std::vector<char> buffer)
{
	internalBuffer = buffer;

	ptrBegin = internalBuffer.data();
	ptrCurrent = ptrBegin;
	ptrEnd = internalBuffer.data() + internalBuffer.size();
	setg(ptrBegin, ptrEnd, ptrEnd);
}

std::streambuf::int_type TStreamable::overflow(std::streambuf::int_type ch)
{
	if (ch == traits_type::eof())
	{
		return traits_type::eof();
	}

	return ch;
}
std::streambuf::int_type TStreamable::underflow()
{
	if (ptrCurrent && ptrCurrent != ptrEnd)
	{
		return traits_type::to_int_type(*ptrCurrent);
	}
	return traits_type::eof();
}

std::streambuf::int_type TStreamable::uflow()
{
	if (ptrCurrent && ptrCurrent != ptrEnd)
	{
		return traits_type::to_int_type(*ptrCurrent++);
	}

	return traits_type::eof();
}
