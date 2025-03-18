#pragma once

class Client
{
	using ServerFactory = function<shared_ptr<Session>()>;
public:
	Client();
	virtual ~Client();

public:
	void Run(endpoint ep);
	void AcceptCompleted(context* acceptContext);

private:
	cppx::socket m_sock;
	ServerFactory m_serverFactory;
};

