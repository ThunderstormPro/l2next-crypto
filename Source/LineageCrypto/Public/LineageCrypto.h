#ifndef H_LINEAGE_CRYPTO
#define H_LINEAGE_CRYPTO

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include "TaskRunner/TaskRunner.h"
#include "TaskRunner/Commands/BaseCommand.h"

// Public export
#include "TaskRunner/Commands/Encrypt.h"
#include "TaskRunner/Commands/Decrypt.h"
#include "Shared/Structs/LineageFileSchema.h"
#include "Utils/Streams/ReadableStream.h"
#include "Utils/Streams/WritableStream.h"


using namespace::std;

class LineageCrypto
{
public:
	static void Enqueue(unique_ptr<BaseCommand>& cmnd);
	// API 
	// Methods.
	template<class T, class A1, class A2>
	static unique_ptr<BaseCommand> Create(A1& a1, A2& a2) {
		return make_unique<T>(a1, a2);
	};
	static void ExecuteAll();
	static void ReleaseAll();

	// Delegates.
	static void OnPassed(const function<void(L2Command&)> callback);
	static void OnFailed(const function<void(L2Command&)> callback);
	
public:
	~LineageCrypto() {};
};

#endif
