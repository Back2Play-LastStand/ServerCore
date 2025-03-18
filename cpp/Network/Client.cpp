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
	auto callback = std::bind(&Client::AcceptCompleted, this, placeholders::_1);
	m_sock.connect(connectContext);
}

void Client::AcceptCompleted(context* acceptContext)
{
	auto client = shared_ptr<Session>();
	client->Run(make_shared<cppx::socket>(m_sock));
	client->OnConnected(endpoint());
}
