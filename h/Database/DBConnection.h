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

	mysqlx::Table GetTable(string schemaName)
	{
		try
		{
			auto table = m_schema->getTable(schemaName);
			cout << "Successful get table " << schemaName << endl;
			return table;
		}
		catch (const mysqlx::Error& err)
		{
			cout << "An error occured : " << err.what() << endl;
		}
	}

	template<typename... Args>
	mysqlx::RowResult Select(mysqlx::Table table, Args... args)
	{
		try
		{
			auto result = table.select(args...).execute();
			return result;
		}
		catch (const mysqlx::Error& err)
		{
			cout << "An error occured : " << err.what() << endl;
		}
	}

private:
	unique_ptr<mysqlx::Schema> m_schema;
	unique_ptr<mysqlx::Session> m_session;
};

