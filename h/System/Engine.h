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

private:
	ThreadManager* m_threadManager = nullptr;
	JobTimer* m_jobTimer = nullptr;
};

extern Engine* GEngine;