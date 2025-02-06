#pragma once

// [size(2)][id(2)][data...]
struct PacketHeader
{
	unsigned short size; // Packet Size
	unsigned short id; // Protocol ID
};

class Packet
{
};

