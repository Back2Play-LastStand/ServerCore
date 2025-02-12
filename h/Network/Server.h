#pragma once

class Server
{
public:
	friend class Session;
	Server();
	virtual ~Server();

public:
	void Run(endpoint ep, int count);
	int AcceptCompleted(context* acceptContext);

private:
	cppx::socket m_listenSocket;
	vector<context*> m_acceptContext;
};

