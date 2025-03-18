#pragma once

class Client
{
public:
	Client();
	virtual ~Client();

public:
	void Run(endpoint ep);
	void AcceptCompleted(context* acceptContext);

private:
	cppx::socket m_sock;
};

