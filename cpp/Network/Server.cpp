#include "pch.h"
#include "Network/Server.h"
#include "Network/Session.h"

Server::Server()
{
	m_listenSocket.create(protocol::tcp);
	m_acceptContext.reserve(20);
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
	SOCKADDR_IN addr;
	int len = sizeof(SOCKADDR_IN);
	if (SOCKET_ERROR != getpeername(acceptContext->_socket->get_handle(), reinterpret_cast<SOCKADDR*>(&addr), &len))
	{
		auto error = WSAGetLastError();
		return WSA_IO_PENDING == error;
	}

	auto endpoint = endpoint::place(addr);
	auto client = shared_ptr<Session>();
	client->Run(move(acceptContext->_socket));
	cppx::socket clientSock = client->GetSocket();
	clientSock.set_endpoint(endpoint);

	acceptContext->_socket = make_shared<cppx::socket>(protocol::tcp);
	client->OnConnected(endpoint);
	m_listenSocket.accept(acceptContext);

	cout << "Complete" << endl;
}
