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
