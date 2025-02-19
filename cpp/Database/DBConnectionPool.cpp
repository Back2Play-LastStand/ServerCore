#include "pch.h"
#include "Database/DBConnectionPool.h"
#include "Database/DBConnection.h"

DBConnectionPool::DBConnectionPool()
{
}

DBConnectionPool::~DBConnectionPool()
{
	Clear();
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

		m_connections.push(connection);
	}

	return true;
}

void DBConnectionPool::Clear()
{
	while (!m_connections.empty())
	{
		DBConnection* connection = nullptr;
		if (m_connections.try_pop(connection))
			xdelete(connection);
	}

	m_connections.clear();
}

void DBConnectionPool::Push(DBConnection* connection)
{
	m_connections.push(connection);
}

DBConnection* DBConnectionPool::Pop()
{
	if (m_connections.empty())
		return nullptr;

	DBConnection* connection = nullptr;
	m_connections.try_pop(connection);
	return connection;
}
