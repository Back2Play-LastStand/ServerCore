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
		shared_ptr<Job> ret = m_jobs.front();
		m_jobs.pop();

		auto job = ret;
		if (job == nullptr)
			break;

		job->Execute();
	}
}
