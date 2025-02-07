#pragma once
using namespace std;
#include <vector>
#include "context.h"

class Session
{
public:
	Session();
	virtual ~Session();

private:
	shared_ptr<cppx::socket> m_sock;
	vector<char> m_buffer;
	cppx::context m_recvContext;
	cppx::context m_sendContext;
};

