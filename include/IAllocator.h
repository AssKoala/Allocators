#pragma once

#include <cstdint>

class IAllocator
{
public:
	virtual ~IAllocator() = default;

	virtual void* Allocate(size_t size, size_t alignment = 0, size_t alignOffset = 0, int64_t flags = 0) = 0;
	virtual void* Reallocate(void* ptr, size_t size, size_t alignment = 0, size_t alignOffset = 0, int64_t flags = 0) = 0;
	virtual void Free(void* ptr) = 0;
};
