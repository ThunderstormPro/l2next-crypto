#ifndef H_BASE_COMMAND
#define H_BASE_COMMAND

#include <memory>
#include "Shared/Enums/CryptoCommands.h"

using namespace::std;

class L2Command
{
public:
	template <typename T>
	T& GetResult() {
		return *static_pointer_cast<T>(_result);
	};

	ECryptoCommands GetId() const;
protected:
	template <typename T>
	void SetResult(shared_ptr<T> any)
	{
		_result = static_pointer_cast<void>(any);
	};

	void SetId(ECryptoCommands id);

private:
	shared_ptr<void> _result;
	ECryptoCommands _id;
};

class BaseCommand: public L2Command
{
public:
	virtual bool Execute();
};

#endif // H_BASE_COMMAND
