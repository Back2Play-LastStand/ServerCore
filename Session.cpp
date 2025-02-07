#include "Session.h"
#include "socket.h"

Session::Session()
{
}

Session::~Session()
{
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
 