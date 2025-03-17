#pragma once

class Client
{
public:
	Client();
	virtual ~Client();

private:
	cppx::socket m_sock;
};

