#pragma once

#include "KoalaAllocator.h"
#include "koala_intrusive_list.h"

class FixedBlockAllocator
	: public KoalaAllocator
{
public:
	FixedBlockAllocator(KoalaAllocator::CoreAllocate coreAllocFunc, size_t coreCount, KoalaAllocator::CoreFree coreFreeFunc, size_t blockSize);

	virtual ~FixedBlockAllocator();

	virtual void* Allocate(size_t size, size_t alignment = 0, size_t alignOffset = 0, int64_t flags = 0);
	virtual void* Reallocate(void* ptr, size_t size, size_t alignment = 0, size_t alignOffset = 0, int64_t flags = 0);
	virtual void Free(void* ptr);

private:
	struct Page
	{
		struct FreeBlock
		{
			FreeBlock* next;
		};

		koala_intrusive_list<FreeBlock>	mFreeBlocks;
		Page* next;
	};

	const size_t				cBlockSize;
	koala_intrusive_list<Page>	mPages;
};
