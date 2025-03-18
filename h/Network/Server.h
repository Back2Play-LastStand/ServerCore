#pragma once
#include "Memory/Memory.h"

class Server
{
	friend class Session;
	using ClientFactory = function<shared_ptr<Session>()>;
public:
	Server();
	virtual ~Server();

public:
	void Run(endpoint ep, int count = 1);
	int AcceptCompleted(context* acceptContext);

	template<typename T>
	static shared_ptr<Server> Make()
	{
		auto server = MakeShared<Server>();
		server->m_serverFactory = [] {
			return MakeShared<T>();
			};
		return server;
	}

private:
	cppx::socket m_listenSocket;
	vector<context*> m_acceptContext;
	ClientFactory m_clientFactory;
};

