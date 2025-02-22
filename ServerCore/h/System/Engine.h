#pragma once

class ThreadManager;
class JobTimer;

class Engine
{
public:
	Engine();
	~Engine();

	void Init();

	ThreadManager* GetThreadManager();
	JobTimer* GetJobTimer();

	void RunThread(int io, int worker);
	void GlobalQueueWork();

private:
	void RunIo(int threadCount);
	void RunQueueWorker(int threadCount);

private:
	ThreadManager* m_threadManager = nullptr;
	JobTimer* m_jobTimer = nullptr;

	concurrent_queue<JobSerializer*> m_jobSerializerQueue;
};

extern Engine* GEngine;