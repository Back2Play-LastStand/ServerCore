#pragma once

class Server
{
public:
	Server();
	virtual ~Server();

private:
	cppx::socket m_listenSocket;
};

