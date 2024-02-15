#pragma once

#include "IAllocator.h"

class KoalaAllocator
	: public IAllocator
{
public:
	// "Core" allocation support
	typedef void* (*CoreAllocate)(size_t coreCount);
	typedef void (*CoreFree)(void* corePtr);

	inline KoalaAllocator(CoreAllocate coreAllocationFunc, size_t coreSize, CoreFree coreFreeFunc);

	// IAllocator interface
	virtual ~KoalaAllocator() = default;

	virtual void* Allocate(size_t size, size_t alignment = 0, size_t alignOffset = 0, int64_t flags = 0) = 0;
	virtual void* Reallocate(void* ptr, size_t size, size_t alignment = 0, size_t alignOffset = 0, int64_t flags = 0) = 0;
	virtual void Free(void* ptr) = 0;

protected: 
	inline void*	AllocateCore(size_t coreCount);
	inline void		FreeCore(void* core);
	inline size_t	GetCoreSize() const;

private:
	inline CoreAllocate GetCoreAllocator();
	inline CoreFree		GetCoreFree();

	CoreAllocate	mCoreAllocFunc;
	CoreFree		mCoreFreeFunc;
	size_t			mCoreSize;
};
 
/* Implementation */

KoalaAllocator::KoalaAllocator(CoreAllocate coreAllocationFunc, size_t coreSize, CoreFree coreFreeFunc)
	:	mCoreAllocFunc(coreAllocationFunc)
	,	mCoreSize(coreSize)
	,	mCoreFreeFunc(coreFreeFunc)
{

}

KoalaAllocator::CoreAllocate KoalaAllocator::GetCoreAllocator() 
{ 
	return mCoreAllocFunc; 
};

KoalaAllocator::CoreFree KoalaAllocator::GetCoreFree()
{ 
	return mCoreFreeFunc; 
}

size_t KoalaAllocator::GetCoreSize() const
{
	return mCoreSize;
}

void* KoalaAllocator::AllocateCore(size_t coreCount)
{
	if (coreCount > 0)
	{
		GetCoreAllocator()(coreCount);
	}

	return nullptr;
}

void KoalaAllocator::FreeCore(void* core)
{
	if (core)
	{
		GetCoreFree()(core);
	}
}
