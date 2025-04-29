#include "DBConnection.h"

MySqlConnection^ DBConnection::GetConnection()
{
    MySqlConnection^ conn = gcnew MySqlConnection(connectionString);
    return conn;
}
