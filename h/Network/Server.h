#pragma once

class Server
{
public:
	friend class Session;
	Server();
	virtual ~Server();

public:
	void Run(endpoint ep, int count = 1);
	int AcceptCompleted(context* acceptContext);

private:
	cppx::socket m_listenSocket;
	vector<context*> m_acceptContext;
};

