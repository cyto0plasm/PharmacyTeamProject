#include "PharmaciesController.h"
#include "../Database/DBConnection.h"
#include "../Models/PharmacyModel.h"
using namespace PMST;
bool PharmaciesController::CreatePharmacy(PharmacyModel^ pharmacy)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "INSERT INTO pharmacies (owner_id, name, location) VALUES (@owner_id, @name, @location)";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@owner_id", pharmacy->Owner_Id);
        cmd->Parameters->AddWithValue("@name", pharmacy->Name);
        cmd->Parameters->AddWithValue("@location", pharmacy->Location);
        return (cmd->ExecuteNonQuery() > 0);
    }
    catch (Exception^ ex) {
        throw gcnew Exception("CreatePharmacy Error", ex);
    }
    finally {
        conn->Close();
    }
}

List<PharmacyModel^>^ PharmaciesController::GetAllPharmacies()
{
    auto list = gcnew List<PharmacyModel^>();
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "SELECT * FROM pharmacies";
        auto cmd = gcnew MySqlCommand(query, conn);
        auto reader = cmd->ExecuteReader();
        while (reader->Read()) {
            auto m = gcnew PharmacyModel();
            m->Id = reader->GetInt32("id");
            m->Owner_Id = reader->GetInt32("owner_id");
            m->Name = reader->GetString("name");
            m->Location = reader->GetString("location");
            m->Created_At = reader->GetDateTime("created_at");
            m->Updated_At = reader->GetDateTime("updated_at");
            list->Add(m);
        }
    }
    catch (Exception^ ex) {
        throw gcnew Exception("GetAllPharmacies Error", ex);
    }
    finally {
        conn->Close();
    }
    return list;
}

void PharmaciesController::UpdatePharmacy(PharmacyModel^ pharmacy)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "UPDATE pharmacies SET owner_id=@owner_id, name=@name, location=@location WHERE id=@id";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@owner_id", pharmacy->Owner_Id);
        cmd->Parameters->AddWithValue("@name", pharmacy->Name);
        cmd->Parameters->AddWithValue("@location", pharmacy->Location);
        cmd->Parameters->AddWithValue("@id", pharmacy->Id);
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("UpdatePharmacy Error", ex);
    }
    finally {
        conn->Close();
    }
}

void PharmaciesController::DeletePharmacy(int id)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "DELETE FROM pharmacies WHERE id=@id";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("DeletePharmacy Error", ex);
    }
    finally {
        conn->Close();
    }
}