#include "pch.h"
#include "Network/Packet.h"

Packet::~Packet()
{
}

vector<char> Packet::GetData()
{
	return m_buffer;
}

void Packet::Set(PacketInfo& packet)
{
	m_packetInfo.clientIndex = packet.clientIndex;
	m_packetInfo.packetHeader = packet.packetHeader;
	m_packetInfo.data = new char[packet.packetHeader.size];
	CopyMemory(m_packetInfo.data, packet.data, packet.packetHeader.size);
}

void Packet::Set(unsigned int clientIndex, PacketHeader packetHeader, char* data)
{
	m_packetInfo.clientIndex = clientIndex;
	m_packetInfo.packetHeader = packetHeader;
	m_packetInfo.data = new char[packetHeader.size];
	CopyMemory(m_packetInfo.data, data, packetHeader.size);
}
