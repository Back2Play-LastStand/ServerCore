#pragma once

// [size(2)][id(2)][data...]
struct PacketHeader
{
	unsigned short size; // Packet Size
	unsigned short id; // Protocol ID
};

struct PacketInfo
{
	unsigned int clientIndex = 0;
	PacketHeader packetHeader;
	char* data = nullptr;
};

class Packet
{
public:
	Packet() = default;
	virtual ~Packet();

	vector<char> GetData();
	void Set(PacketInfo& packet);
	void Set(unsigned int clientIndex, PacketHeader packetHeader, char* data);

private:
	vector<char> m_buffer;
	PacketInfo m_packetInfo;
};

