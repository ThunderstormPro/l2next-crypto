#ifndef H_EVENT_TEMPLATE
#define H_EVENT_TEMPLATE

#include <functional>
#include <vector>

template<class T>
struct EventTemplate
{
public:
	typedef std::function<void(T)> Functor;

protected:
	void Add(Functor func)
	{
		eventContainer.push_back(func);
	}

	void Call(T data)
	{
		for (auto& ev : eventContainer)
		{
			ev(data);
		}
	}

private:
	std::vector<Functor> eventContainer;
};


#endif // H_EVENT_TEMPLATE
