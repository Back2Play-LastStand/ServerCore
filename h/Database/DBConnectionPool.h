#pragma once

class DBConnection;

class DBConnectionPool
{
public:
	DBConnectionPool();
	~DBConnectionPool();

	bool Connection(int connectionCount);
	void Clear();

private:
	concurrent_queue<DBConnection*> m_connections;
};

