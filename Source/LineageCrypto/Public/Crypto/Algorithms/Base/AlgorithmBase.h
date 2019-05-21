#ifndef H_ALGORITHM_BASE
#define H_ALGORITHM_BASE

using namespace::std;

class AlgorithmBase
{
public:
	/** Methods */
	virtual void SetInputData(const char* buffer);
	virtual void GetExecResult(char*& result) {};
	virtual void Reset();

protected:
	const char* GetBuffer() const;

private:
	const char* _buffer = nullptr;
};

#endif // H_ALGORITHM_BASE
