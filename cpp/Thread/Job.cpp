#include "pch.h"
#include "Thread/Job.h"

void JobSerializer::PushJob(CallbackJob&& callback)
{
	auto job = MakeShared<Job>(move(callback));
	m_jobs.push(job);
}

