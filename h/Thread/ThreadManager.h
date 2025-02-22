#pragma once

class ThreadManager
{
public:
	ThreadManager();
	~ThreadManager();

	void Launch(function<void(void)> callback);
	void Join();

	static void InitTLS();
	static void DestoryTLS();

private:
	concurrent_vector<thread> m_threads;
};

