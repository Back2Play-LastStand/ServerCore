#include "pch.h"
#include "Network/Client.h"
#include "Network/Session.h"

Client::Client()
{
	m_sock.create(protocol::tcp);
}

Client::~Client()
{
}

void Client::Run(endpoint ep)
{
	m_sock.set_endpoint(ep);

	auto connectContext = new context;
	connectContext->_socket = make_shared<cppx::socket>();
	connectContext->endpoint = make_shared<endpoint>(ep);
	auto result = m_sock.connect(connectContext);

	if (result)
		AcceptCompleted(connectContext);
}

void Client::AcceptCompleted(context* acceptContext)
{
	auto client = make_shared<Session>();
	client->Run(move(make_shared<cppx::socket>(m_sock)));
	client->OnConnected(endpoint());
}
