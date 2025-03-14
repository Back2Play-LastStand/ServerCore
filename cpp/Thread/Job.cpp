#include "pch.h"
#include "Thread/Job.h"

void JobSerializer::FlushJob()
{
	while (!m_jobs.empty())
	{
		shared_ptr<Job> job;
		if (m_jobs.try_pop(job))
		{
			job->Execute();
			m_jobCount.fetch_sub(1);
		}
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

void JobTimer::Reserve(unsigned long long executeTick, weak_ptr<JobSerializer> owner, shared_ptr<Job> job)
{
	m_datas.push({ GetTickCount64() + executeTick, owner, job });
}

void JobTimer::Distribute(unsigned long long now)
{
	while (!m_datas.empty())
	{
		JobData jobData;
		if (m_datas.try_pop(jobData))
		{
			if (now < jobData.executeTick)
			{
				m_datas.push(jobData);
				break;
			}
			else if (auto owner = jobData.owner.lock())
				owner->Push(jobData.job);
		}
	}
}

void JobTimer::Clear()
{
	while (!m_datas.empty())
	{
		m_datas.clear();
	}
}