#pragma once
#include "Memory/Memory.h"

class Client
{
	friend class Session;
	using ServerFactory = function<shared_ptr<Session>()>;
public:
	Client();
	virtual ~Client();

public:
	void Run(endpoint ep);
	void AcceptCompleted(context* acceptContext);

	template<typename T>
	static shared_ptr<Client> Make()
	{
		auto client = MakeShared<Client>();
		client->m_serverFactory = [] {
			return MakeShared<T>();
			};
		return client;
	}

private:
	cppx::socket m_sock;
	ServerFactory m_serverFactory;
};

