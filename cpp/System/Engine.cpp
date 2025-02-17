#include "pch.h"
#include "System/Engine.h"

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

