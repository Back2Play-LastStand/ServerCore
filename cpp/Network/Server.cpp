#include "pch.h"
#include "Network\Server.h"

Server::Server()
{
	m_listenSocket.create(protocol::tcp);
}

Server::~Server()
{
}
