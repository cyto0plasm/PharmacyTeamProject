#include "UsersController.h"
#include "../Database/DBConnection.h"
#include "../Models/UserModel.h"
using namespace PMST;
bool UsersController::CreateUser(UserModel^ user)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "INSERT INTO users (username, password, email) VALUES (@username, @password, @email)";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@username", user->Username);
        cmd->Parameters->AddWithValue("@password", user->Password);
        cmd->Parameters->AddWithValue("@email", user->Email);
        return (cmd->ExecuteNonQuery() > 0);
    }
    catch (Exception^ ex) {
        throw gcnew Exception("CreateUser Error", ex);
    }
    finally {
        conn->Close();
    }
}

List<UserModel^>^ UsersController::GetAllUsers()
{
    auto list = gcnew List<UserModel^>();
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "SELECT * FROM users";
        auto cmd = gcnew MySqlCommand(query, conn);
        auto reader = cmd->ExecuteReader();
        while (reader->Read()) {
            auto m = gcnew UserModel();
            m->Id = reader->GetInt32("id");
            m->Username = reader->GetString("username");
            m->Password = reader->GetString("password");
            m->Email = reader->GetString("email");
            m->Created_At = reader->GetDateTime("created_at");
            m->Updated_At = reader->GetDateTime("updated_at");
            list->Add(m);
        }
    }
    catch (Exception^ ex) {
        throw gcnew Exception("GetAllUsers Error", ex);
    }
    finally {
        conn->Close();
    }
    return list;
}

void UsersController::UpdateUser(UserModel^ user)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "UPDATE users SET username=@username, password=@password, email=@email WHERE id=@id";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@username", user->Username);
        cmd->Parameters->AddWithValue("@password", user->Password);
        cmd->Parameters->AddWithValue("@email", user->Email);
        cmd->Parameters->AddWithValue("@id", user->Id);
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("UpdateUser Error", ex);
    }
    finally {
        conn->Close();
    }
}

void UsersController::DeleteUser(int id)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "DELETE FROM users WHERE id=@id";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("DeleteUser Error", ex);
    }
    finally {
        conn->Close();
    }
}