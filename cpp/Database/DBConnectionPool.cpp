#include "pch.h"
#include "Database/DBConnectionPool.h"
#include "Database/DBConnection.h"

DBConnectionPool::DBConnectionPool()
{
}

DBConnectionPool::~DBConnectionPool()
{
}

bool DBConnectionPool::Connection(int connectionCount)
{
	if (connectionCount == 0)
		return false;

	for (int i = 0; i < connectionCount; i++)
	{
		DBConnection* connection = xnew<DBConnection>();
		if (connection->Connect() == false)
			return false;

		m_connections.push_back(connection);
	}

	return true;
}

void DBConnectionPool::Clear()
{
	for (auto* connection : m_connections)
		xdelete(connection);

	m_connections.clear();
}
