#pragma once
#include "context.h"
#include "Packet.h"

class Session : public enable_shared_from_this<Session>
{
public:
	Session();
	virtual ~Session();

public:
	void Run(shared_ptr<cppx::socket> sock);
	cppx::socket GetSocket();

public:
	void Send(Packet* packet, bool sendContext = true);
	void SendChar(vector<char> buffer);
	void SendContext(vector<char> buffer);
	void Disconnect();

public:
	virtual void OnConnected(endpoint ep) { }
	virtual void OnRecv(byte* buffer, int len) { }
	virtual void OnSend(int len) { }
	virtual void OnDisconnected() { }

private:
	shared_ptr<cppx::socket> m_sock;
	vector<char> m_buffer;
	cppx::context m_recvContext;
	cppx::context m_sendContext;

	atomic<bool> m_connected;
};

