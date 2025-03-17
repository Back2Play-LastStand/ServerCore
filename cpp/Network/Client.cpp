#include "pch.h"
#include "Network/Client.h"

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
	m_sock.connect(connectContext);
}
