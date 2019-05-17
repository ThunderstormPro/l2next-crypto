#ifndef H_COMMAND
#define H_COMMAND

using namespace::std;

class ICommand
{
public:
	/** Methods */
	virtual bool Execute() = 0;
};

#endif // H_COMMAND