#include "StockHistoryController.h"
#include "../Database/DBConnection.h"
#include "../Models/StockHistoryModel.h"
using namespace PMST;
bool StockHistoryController::CreateHistoryEntry(StockHistoryModel^ entry)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "INSERT INTO stock_history (pharmacy_id, product_id, change_type, quantity_changed, note) "
            "VALUES (@pharmacy_id, @product_id, @change_type, @quantity_changed, @note)";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@pharmacy_id", entry->Pharmacy_Id);
        cmd->Parameters->AddWithValue("@product_id", entry->Product_Id);
        cmd->Parameters->AddWithValue("@change_type", entry->Change_Type);
        cmd->Parameters->AddWithValue("@quantity_changed", entry->Quantity_Changed);
        cmd->Parameters->AddWithValue("@note", entry->Note);
        return (cmd->ExecuteNonQuery() > 0);
    }
    catch (Exception^ ex) {
        throw gcnew Exception("CreateHistoryEntry Error", ex);
    }
    finally {
        conn->Close();
    }
}

List<StockHistoryModel^>^ StockHistoryController::GetAllHistory()
{
    auto list = gcnew List<StockHistoryModel^>();
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "SELECT * FROM stock_history";
        auto cmd = gcnew MySqlCommand(query, conn);
        auto reader = cmd->ExecuteReader();
        while (reader->Read()) {
            auto m = gcnew StockHistoryModel();
            m->Id = reader->GetInt32("id");
            m->Pharmacy_Id = reader->GetInt32("pharmacy_id");
            m->Product_Id = reader->GetInt32("product_id");
            m->Change_Type = reader->GetString("change_type");
            m->Quantity_Changed = reader->GetInt32("quantity_changed");
            m->Note = reader->IsDBNull(reader->GetOrdinal("note")) ? "" : reader->GetString("note");
            m->Created_At = reader->GetDateTime("created_at");
            m->Updated_At = reader->GetDateTime("updated_at");
            list->Add(m);
        }
    }
    catch (Exception^ ex) {
        throw gcnew Exception("GetAllHistory Error", ex);
    }
    finally {
        conn->Close();
    }
    return list;
}

void StockHistoryController::UpdateHistoryEntry(StockHistoryModel^ entry)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "UPDATE stock_history SET pharmacy_id=@pharmacy_id, product_id=@product_id, "
            "change_type=@change_type, quantity_changed=@quantity_changed, note=@note WHERE id=@id";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@pharmacy_id", entry->Pharmacy_Id);
        cmd->Parameters->AddWithValue("@product_id", entry->Product_Id);
        cmd->Parameters->AddWithValue("@change_type", entry->Change_Type);
        cmd->Parameters->AddWithValue("@quantity_changed", entry->Quantity_Changed);
        cmd->Parameters->AddWithValue("@note", entry->Note);
        cmd->Parameters->AddWithValue("@id", entry->Id);
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("UpdateHistoryEntry Error", ex);
    }
    finally {
        conn->Close();
    }
}

void StockHistoryController::DeleteHistoryEntry(int id)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "DELETE FROM stock_history WHERE id=@id";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("DeleteHistoryEntry Error", ex);
    }
    finally {
        conn->Close();
    }
}