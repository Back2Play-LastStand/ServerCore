#pragma once

#include <thread>
#include <functional>

class ThreadManager
{
public:
	ThreadManager();
	~ThreadManager();
private:
	mutex m_lock;
	vector<thread> m_threads;
};

