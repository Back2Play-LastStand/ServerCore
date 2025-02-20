#include "pch.h"
#include "Database/DBConnection.h"

bool DBConnection::Connect()
{
	try
	{

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
