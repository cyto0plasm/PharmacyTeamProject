#pragma once

using namespace System;
using namespace MySql::Data::MySqlClient;

ref class DBConnection
{
private:
    static String^ connectionString = "server=localhost;port=3306;user=root;password=;database=pharmacy_management_system;";
public:
    static MySqlConnection^ GetConnection();
};