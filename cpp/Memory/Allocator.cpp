#include "pch.h"
#include "Memory/Allocator.h"

void* StompAllocator::Alloc(int size)
{
	const long long pageCount = (size + PAGE_SIZE - 1) / PAGE_SIZE;
	const long long dataOffset = pageCount * PAGE_SIZE - size;
	void* baseAddress = ::VirtualAlloc(NULL, pageCount + PAGE_SIZE, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	return static_cast<void*>(static_cast<char*>(baseAddress) + dataOffset);
}

void StompAllocator::Release(void* ptr)
{
	const long long address = reinterpret_cast<long long>(ptr);
	const long long baseAddress = address - (address % PAGE_SIZE);
	::VirtualFree(reinterpret_cast<void*>(baseAddress), 0, MEM_RELEASE);
}

void* PoolAllocator::Alloc(int size)
{
	return GMemory->Allocate(size);
}

void PoolAllocator::Release(void* ptr)
{
	GMemory->Release(ptr);
}