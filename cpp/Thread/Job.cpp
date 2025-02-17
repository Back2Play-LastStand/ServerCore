#include "pch.h"
#include "Thread/Job.h"

void JobSerializer::FlushJob()
{
	while (!m_jobs.empty())
	{
		shared_ptr<Job> job;
		if (m_jobs.try_pop(job))
			job->Execute();
	}
}

void JobSerializer::Push(shared_ptr<Job> job)
{
	const int prevCount = m_jobCount.fetch_add(1);
	m_jobs.push(job);

	if (prevCount == 0)
	{
		FlushJob();
	}
}