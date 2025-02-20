#pragma once
#include <sql.h>
#include <sqlext.h>

class DBConnection
{
public:
	DBConnection() = default;

	bool Connect();
	void Clear();

	bool Execute();
};

