#pragma once

class StompAllocator
{
	enum { PAGE_SIZE = 0x1000 };

public:
	static void* Alloc(int size);
	static void Release(void* ptr);
};

class PoolAllocator
{
	enum { PAGE_SIZE = 0x1000 };
public:
	static void* Alloc(int size);
	static void Release(void* ptr);

};