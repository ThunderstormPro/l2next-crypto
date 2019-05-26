#ifndef H_LINEAGE_CRYPTO
#define H_LINEAGE_CRYPTO

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TaskRunner/TaskRunner.h"
#include "TaskRunner/Commands/BaseCommand.h"
#include "TaskRunner/Commands/Encrypt.h"
#include "TaskRunner/Commands/Decrypt.h"
#include "Shared/Structs/LineageFileSchema.h"
#include <functional>
#include <string>

using namespace::std;

class LineageCrypto
{
public:
	// API
	static void Enqueue(BaseCommand& cmnd);
	static void ExecuteAll();
	static void Release();

	// Delegates.
	static void OnPassed(const function<void(L2Command&)> callback);
	static void OnFailed(const function<void(L2Command&)> callback);
	
public:
	~LineageCrypto() {};
};

#endif
