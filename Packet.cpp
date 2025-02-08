#include "Packet.h"

Packet::~Packet()
{
}

vector<char> Packet::GetData()
{
	return m_buffer;
}
