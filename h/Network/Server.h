#pragma once

class Server
{
public:
	Server();
	virtual ~Server();

	void Run(endpoint ep, int count);
	int AcceptCompleted(context* acceptContext);

private:
	cppx::socket m_listenSocket;
	vector<context> m_acceptContext;
};

