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
	concurrent_vector<DBConnection*> m_connections;
};

