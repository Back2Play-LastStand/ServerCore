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

void Engine::RunThread(int io, int worker)
{
	RunIo(io);
	RunQueueWorker(worker);
}

void Engine::RunIo(int threadCount)
{
	for (int i = 0;i < threadCount; i++)
	{
		m_threadManager->Launch([=]()
			{
				while (true)
				{
					native::gqcs();
				}
			});
	}
}

void Engine::RunQueueWorker(int threadCount)
{
	for (int i = 0;i < threadCount; i++)
	{
		m_threadManager->Launch([=]()
			{
				GlobalQueueWork();
			});
	}
}

void Engine::GlobalQueueWork()
{
	while (true)
	{
		m_jobTimer->Distribute(GetTickCount64());

		if (!m_jobSerializerQueue.empty())
		{
			JobSerializer* jobSerializer;
			if (m_jobSerializerQueue.try_pop(jobSerializer))
			{
				jobSerializer->FlushJob();
			}
		}
		this_thread::sleep_for(chrono::milliseconds(1));
	}
}

Engine* GEngine = nullptr;