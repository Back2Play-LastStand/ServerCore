#pragma once
#include "Memory/MemoryPool.h"

template<typename T>
class ObjectPool
{
public:
	template<typename... Args>
	static T* Pop(Args&&... args)
	{
#ifdef _STOMP
		MemoryHeader* ptr = reinterpret_cast<MemoryHeader*>(StompAllocator::Alloc(s_allocSize));
		T* memory = static_cast<T*>(MemoryHeader::AttachHeader(ptr, s_allocSize));
#else
		T* memory = static_cast<T*>(MemoryHeader::AttachHeader(s_pool.Pop(), s_allocSize));
#endif
		new(memory)T(forward<Args>(args)...);
		return memory;
	}

	static void Push(T* obj)
	{
		obj->~T();
#ifdef _STOMP
		StompAllocator::Release(MemoryHeader::DetachHeader(obj));
#else
		s_pool.Push(MemoryHeader::DetachHeader(obj));
#endif
	}

	static shared_ptr<T> MakeShared()
	{
		shared_ptr<T> ptr = { Pop(), Push };
		return ptr;
	}

private:
	static int s_allocSize;
	static MemoryPool s_pool;
};

template<typename T>
int ObjectPool<T>::s_allocSize = sizeof(T) + sizeof(MemoryHeader);

template<typename T>
MemoryPool ObjectPool<T>::s_pool{ s_allocSize };