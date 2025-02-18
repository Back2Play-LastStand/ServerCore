#include "pch.h"
#include "System/Engine.h"

#include "Thread/ThreadManager.h"
#include "Thread/Job.h"

Engine::Engine()
{
	Init();
}

Engine::~Engine()
{
	delete m_threadManager;
	delete m_jobTimer;
}

void Engine::Init()
{
	m_threadManager = new ThreadManager;
	m_jobTimer = new JobTimer;
}

ThreadManager* Engine::GetThreadManager()
{
	return m_threadManager;
}

JobTimer* Engine::GetJobTimer()
{
	return m_jobTimer;
}

Engine* GEngine = nullptr;