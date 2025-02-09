#pragma once
#include <vector>
using namespace std;

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

private:
	vector<char> m_buffer;
};

