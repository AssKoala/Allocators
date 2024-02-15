#include "FixedBlockAllocator.h"
#include <cassert>


FixedBlockAllocator::FixedBlockAllocator(KoalaAllocator::CoreAllocate coreAllocFunc, size_t coreCount, KoalaAllocator::CoreFree coreFreeFunc, size_t blockSize)
	: KoalaAllocator(coreAllocFunc, coreCount, coreFreeFunc)
	, cBlockSize(blockSize)
{
	assert(cBlockSize <= GetCoreSize());
	assert(cBlockSize >= sizeof(intptr_t));
}

FixedBlockAllocator::~FixedBlockAllocator()
{

}

#pragma warning(disable:4100)

void* FixedBlockAllocator::Allocate(size_t size, size_t alignment, size_t alignOffset, int64_t flags)
{
	if (size > cBlockSize)
		return nullptr;

	for (auto& page : mPages)
	{

	}
	return nullptr;
}

void* FixedBlockAllocator::Reallocate(void* ptr, size_t size, size_t alignment, size_t alignOffset, int64_t flags)
{
	return nullptr;
}

void FixedBlockAllocator::Free(void* ptr)
{

}
