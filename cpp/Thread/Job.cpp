#include "pch.h"
#include "Thread/Job.h"

void JobSerializer::PushJob(CallbackJob&& callback)
{
	auto job = MakeShared<Job>(move(callback));
	m_jobs.push(job);
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
