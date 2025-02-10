#include "pch.h"
#include "Network\Server.h"
#include "Network/Session.h"

Server::Server()
{
	m_listenSocket.create(protocol::tcp);
}

Server::~Server()
{
}

void Server::Run(endpoint ep, int count)
{
	if (!m_listenSocket.bind(endpoint(ep)))
	{
		cout << "bind error" << endl;
		return;
	}
	if (!m_listenSocket.listen())
	{
		cout << "listen error" << endl;
		return;
	}

	for (int i = 0; i < count; i++)
	{
		auto acceptContext = new context;
		acceptContext->_socket = make_shared<cppx::socket>(protocol::tcp);
		
		if (!m_listenSocket.accept(acceptContext))
			AcceptCompleted(acceptContext);

		m_acceptContext.emplace_back(acceptContext);
	}
}

int Server::AcceptCompleted(context* acceptContext)
{
}
