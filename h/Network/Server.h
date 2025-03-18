#pragma once

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

private:
	cppx::socket m_listenSocket;
	vector<context*> m_acceptContext;
	ClientFactory m_clientFactory;
};

