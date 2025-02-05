#include <iostream>
using namespace std;

#include "socket.h"
using namespace cppx;

int main()
{
	native::init(5);
	cppx::socket sock(protocol::tcp);
	if (!sock.not_invalid())
		return -1;
	if (!sock.bind(endpoint(ip_address::any, 7777)))
		return -1;
	if (!sock.listen())
		return -1;

	while (true)
	{

	}

	return 0;
}