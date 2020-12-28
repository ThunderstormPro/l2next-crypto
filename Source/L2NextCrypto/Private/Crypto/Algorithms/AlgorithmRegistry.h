#ifndef H_ALGORITHM_REGISTRY
#define H_ALGORITHM_REGISTRY

#include <memory>
#include <string>
#include <algorithm>
#include <unordered_set> 
#include <iostream>
#include "Base/Algorithm.h"
#include "41x/Versions/Ver411.h"
#include "41x/Versions/Ver412.h"
#include "41x/Versions/Ver413.h"
#include "41x/Versions/Ver414.h"

class AlgorithmRegistry
{
public:
	struct AlgorithmHasher {
		size_t operator()(const std::unique_ptr<Algorithm>& ptr) const {
			return std::hash<int>()(ptr->GetVersion());
		}
	};

	struct AlgorithmComparator {
		bool operator()(const std::unique_ptr<Algorithm>& ptr1, const std::unique_ptr<Algorithm>& ptr2) const {
			return ptr1->GetVersion() == ptr2->GetVersion() ? true : false;
		}
	};

	static AlgorithmRegistry& GetInstance()
	{
		static AlgorithmRegistry instance;
		return instance;
	}

	/**
	 * Check if version is supported by crypto module.
	 * @param const int& version version to check for.
	 * @return bool is supported or not.
	 */
	bool IsSupported(const int& version);

	/**
	 * Gets algorithm 
	 * @param const int& version version to check for.
	 * @param AlgorithmBase& algorithm ref to pass the algorithm to.
	 * @return bool was found or not.
	 */
	bool Get(const int& version, Algorithm*& algorithm);


public:
	AlgorithmRegistry();
	~AlgorithmRegistry();

	AlgorithmRegistry(AlgorithmRegistry const&) = delete;             // Copy construct
	AlgorithmRegistry(AlgorithmRegistry&&) = delete;                  // Move construct
	AlgorithmRegistry& operator=(AlgorithmRegistry const&) = delete;  // Copy assign
	AlgorithmRegistry& operator=(AlgorithmRegistry &&) = delete;      // Move assign

private:
	/* All supported crypt algorithms for Lineage2 files */
	std::unordered_set<std::unique_ptr<Algorithm>, AlgorithmHasher, AlgorithmComparator> algorithms;

	template<class T>
	void Add()
	{
		algorithms.insert(std::move(std::make_unique<T>()));
	}
};

#endif // H_ALGORITHM_REGISTRY
