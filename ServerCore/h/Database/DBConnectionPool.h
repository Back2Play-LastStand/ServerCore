#pragma once

class DBConnection;

class DBConnectionPool
{
public:
	DBConnectionPool();
	~DBConnectionPool();

	bool Connection(int connectionCount, string schemaName);
	void Clear();

	void Push(DBConnection* connection);
	DBConnection* Pop();

private:
	concurrent_queue<DBConnection*> m_connections;
};

