#include "SuppliersController.h"
#include "../Database/DBConnection.h"
#include "../Models/SupplierModel.h"
using namespace PMST;
bool SuppliersController::CreateSupplier(SupplierModel^ supplier)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "INSERT INTO suppliers (pharmacy_id, name, contact_info) VALUES (@pharmacy_id, @name, @contact_info)";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@pharmacy_id", supplier->Pharmacy_Id);
        cmd->Parameters->AddWithValue("@name", supplier->Name);
        cmd->Parameters->AddWithValue("@contact_info", supplier->Contact_Info);
        return (cmd->ExecuteNonQuery() > 0);
    }
    catch (Exception^ ex) {
        throw gcnew Exception("CreateSupplier Error", ex);
    }
    finally {
        conn->Close();
    }
}

List<SupplierModel^>^ SuppliersController::GetAllSuppliers()
{
    auto list = gcnew List<SupplierModel^>();
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "SELECT * FROM suppliers";
        auto cmd = gcnew MySqlCommand(query, conn);
        auto reader = cmd->ExecuteReader();
        while (reader->Read()) {
            auto m = gcnew SupplierModel();
            m->Id = reader->GetInt32("id");
            m->Pharmacy_Id = reader->GetInt32("pharmacy_id");
            m->Name = reader->GetString("name");
            m->Contact_Info = reader->IsDBNull(reader->GetOrdinal("contact_info")) ? "" : reader->GetString("contact_info");
            m->Created_At = reader->GetDateTime("created_at");
            m->Updated_At = reader->GetDateTime("updated_at");
            list->Add(m);
        }
    }
    catch (Exception^ ex) {
        throw gcnew Exception("GetAllSuppliers Error", ex);
    }
    finally {
        conn->Close();
    }
    return list;
}

void SuppliersController::UpdateSupplier(SupplierModel^ supplier)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "UPDATE suppliers SET pharmacy_id=@pharmacy_id, name=@name, contact_info=@contact_info WHERE id=@id";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@pharmacy_id", supplier->Pharmacy_Id);
        cmd->Parameters->AddWithValue("@name", supplier->Name);
        cmd->Parameters->AddWithValue("@contact_info", supplier->Contact_Info);
        cmd->Parameters->AddWithValue("@id", supplier->Id);
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("UpdateSupplier Error", ex);
    }
    finally {
        conn->Close();
    }
}

void SuppliersController::DeleteSupplier(int id)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "DELETE FROM suppliers WHERE id=@id";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("DeleteSupplier Error", ex);
    }
    finally {
        conn->Close();
    }
}