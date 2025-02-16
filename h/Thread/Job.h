#pragma once

using CallbackJob = function<void()>;

class Job
{
public:
	Job(CallbackJob&& callback) : m_callback(move(callback))
	{
	}

	template<typename T, typename Ret, typename... Args>
	Job(shared_ptr<T> owner, Ret(T::* memFunc)(Args...), Args&&... args)
	{
		m_callback = [owner, memFunc, args...]()
			{
				(owner.get()->*memFunc)(args...);
			};
	}

	void Execute()
	{
		m_callback;
	}

private:
	CallbackJob m_callback;
};

class JobSerializer : public enable_shared_from_this<JobSerializer>
{
public:
	void PushJob(CallbackJob&& callback)
	{
		m_jobs.push(MakeShared<Job>(move(callback)));
	}

	template<typename T, typename Ret, typename... Args>
	void PushJob(Ret(T::* memFunc)(Args...), Args... args)
	{
		auto owner = static_pointer_cast<T>(shared_from_this());
		auto job = MakeShared<Job>(owner, memFunc, forward<Args>(args)...);
		m_jobs.push(job);
	}

	void FlushJob();

private:
	concurrent_queue<shared_ptr<Job>> m_jobs;
};