#include "pch.h"
#include "Database/DBConnection.h"

void DBConnection::InitMysql(string schemaName)
{
	const char* url = ("mysqlx://root:1234@127.0.0.1");
	cout << "Creating session on " << url << "..." << endl;
	m_session = make_unique<mysqlx::Session>(url);

	cout << "Session accepted, getting schemas..." << endl;
	m_schema = make_unique<mysqlx::Schema>(m_session->getSchema(schemaName));
}

bool DBConnection::Connect(string schemaName)
{
	try
	{
		InitMysql(schemaName);
	}
	catch (const int error)
	{
		return false;
	}

	return true;
}

void DBConnection::Clear()
{
}

bool DBConnection::Execute()
{
	return false;
}
