#include "pch.h"
#include "Thread/Job.h"

void JobSerializer::PushJob(CallbackJob&& callback)
{
	m_jobs.push(MakeShared<Job>(move(callback)));
}

void JobSerializer::FlushJob()
{
	while (!m_jobs.empty())
	{
		shared_ptr<Job> job;
		if (m_jobs.try_pop(job))
			job->Execute();
	}
}
