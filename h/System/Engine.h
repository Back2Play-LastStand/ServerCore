#pragma once

class Engine
{
public:
	Engine();
	~Engine();

private:
	ThreadManager* m_threadManager = nullptr;
	JobTimer* m_jobTimer = nullptr;
};

extern class Engine* GEngine;