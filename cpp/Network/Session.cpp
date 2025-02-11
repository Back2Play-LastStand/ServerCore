#include "pch.h"
#include "Network/Session.h"

Session::Session()
{
}

Session::~Session()
{
}

void Session::Run(shared_ptr<cppx::socket> sock)
{
	m_sock = sock;
	m_recvContext._buffer = m_buffer;
	m_sock->recv(&m_recvContext);
}

cppx::socket Session::GetSocket()
{
	return *m_sock;
}

void Session::Send(Packet* packet, bool sendContext = true)
{
	if (sendContext)
		SendContext(packet->GetData());
	else
		SendChar(packet->GetData());
}

void Session::SendChar(vector<char> buffer)
{
	m_sock->send(buffer);
}

void Session::SendContext(vector<char> buffer)
{
	m_sendContext._buffer = buffer;
	m_sock->send(&m_sendContext);
}

void Session::Disconnect()
{
}
 