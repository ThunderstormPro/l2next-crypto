#ifndef H_LINEAGE_CRYPTO
#define H_LINEAGE_CRYPTO

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TaskRunner/TaskRunner.h"
#include "TaskRunner/Interfaces/Command.h"
#include "TaskRunner/Commands/Encrypt.h"
#include "TaskRunner/Commands/Decrypt.h"
#include <functional>
#include <string>

using namespace::std;

class LineageCrypto
{
public:
	// API
	static void Enqueue(ICommand& cmnd);
	static void ExecuteAll();
	static void Release();

	// Delegates.
	static void OnPassed(function<void(ICommand&)> callback);
	static void OnFailed(function<void(ICommand&)> callback);
	
public:
	~LineageCrypto() {};
};

#endif
