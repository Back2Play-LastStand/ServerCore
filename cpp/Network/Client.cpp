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
	connectContext->endpoint = make_shared<endpoint>(ep);
	connectContext->completed_callback = std::bind(&Client::AcceptCompleted, this, placeholders::_1, placeholders::_2);
	m_sock.connect(connectContext);
}

void Client::AcceptCompleted(context* acceptContext, bool success)
{
	auto client = m_serverFactory();
	if (success)
	{
		client->Run(move(make_shared<cppx::socket>(m_sock)));
		client->OnConnected(endpoint());
	}
}
