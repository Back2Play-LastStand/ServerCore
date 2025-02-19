#pragma once

class DBConnection;

class DBConnectionPool
{
public:
	DBConnectionPool();
	~DBConnectionPool();

private:
	concurrent_vector<DBConnection*> m_connections;
};

