#pragma once
#include "../Database/DBConnection.h"
#include "../Models/UserModel.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;

namespace PMST {
    public ref class UsersController
    {
    public:
        bool CreateUser(UserModel^ user);
        List<UserModel^>^ GetAllUsers();
        void UpdateUser(UserModel^ user);
        void DeleteUser(int id);
    };
}