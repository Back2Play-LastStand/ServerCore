#pragma once
#include <sql.h>
#include <sqlext.h>

class DBConnection
{
public:
	DBConnection() = default;
	void InitMysql(string schemaName);

	bool Connect(string schemaName);
	void Clear();

	bool Execute();

private:
	unique_ptr<mysqlx::Schema> m_schema;
	unique_ptr<mysqlx::Session> m_session;
};

