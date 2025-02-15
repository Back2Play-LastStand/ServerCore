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
		}
	}


private:
	CallbackJob m_callback;
};

class JobSerializer : public enable_shared_from_this<JobSerializer>
{

};