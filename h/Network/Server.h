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
	void AcceptCompleted(context* acceptContext, bool success);

	template<typename T>
	static shared_ptr<Server> Make()
	{
		auto server = shared_ptr<Server>(new Server);
		server->m_clientFactory = [] {
			return MakeShared<T>();
			};
		return server;
	}

private:
	cppx::socket m_listenSocket;
	vector<context*> m_acceptContext;
	ClientFactory m_clientFactory;

	vector<shared_ptr<Session>> m_clients;
};

