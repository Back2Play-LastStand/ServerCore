#include "pch.h"
#include "Network/Client.h"

Client::Client()
{
	m_sock.create(protocol::tcp);
}

Client::~Client()
{
}
