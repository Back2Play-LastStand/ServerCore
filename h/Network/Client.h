#pragma once

class Client
{
public:
	Client();
	virtual ~Client();

public:
	void Run(endpoint ep);

private:
	cppx::socket m_sock;
};

