#include "SalesController.h"
#include "../Database/DBConnection.h"
#include "../Models/SaleModel.h"
using namespace PMST;
bool SalesController::CreateSale(SaleModel^ sale)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "INSERT INTO sales (pharmacy_id, product_id, user_id, quantity, total_price) "
            "VALUES (@pharmacy_id, @product_id, @user_id, @quantity, @total_price)";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@pharmacy_id", sale->Pharmacy_Id);
        cmd->Parameters->AddWithValue("@product_id", sale->Product_Id);
        cmd->Parameters->AddWithValue("@user_id", safe_cast<Object^>(sale->User_Id));
        cmd->Parameters->AddWithValue("@quantity", sale->Quantity);
        cmd->Parameters->AddWithValue("@total_price", sale->Total_Price);
        return (cmd->ExecuteNonQuery() > 0);
    }
    catch (Exception^ ex) {
        throw gcnew Exception("CreateSale Error", ex);
    }
    finally {
        conn->Close();
    }
}

List<SaleModel^>^ SalesController::GetAllSales()
{
    auto list = gcnew List<SaleModel^>();
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "SELECT * FROM sales";
        auto cmd = gcnew MySqlCommand(query, conn);
        auto reader = cmd->ExecuteReader();
        while (reader->Read()) {
            auto m = gcnew SaleModel();
            m->Id = reader->GetInt32("id");
            m->Pharmacy_Id = reader->GetInt32("pharmacy_id");
            m->Product_Id = reader->GetInt32("product_id");
            m->User_Id = reader->IsDBNull(reader->GetOrdinal("user_id")) ? Nullable<int>() : reader->GetInt32("user_id");
            m->Quantity = reader->GetInt32("quantity");
            m->Total_Price = reader->GetDecimal("total_price");
            m->Created_At = reader->GetDateTime("created_at");
            m->Updated_At = reader->GetDateTime("updated_at");
            list->Add(m);
        }
    }
    catch (Exception^ ex) {
        throw gcnew Exception("GetAllSales Error", ex);
    }
    finally {
        conn->Close();
    }
    return list;
}

void SalesController::UpdateSale(SaleModel^ sale)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "UPDATE sales SET pharmacy_id=@pharmacy_id, product_id=@product_id, user_id=@user_id, "
            "quantity=@quantity, total_price=@total_price WHERE id=@id";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@pharmacy_id", sale->Pharmacy_Id);
        cmd->Parameters->AddWithValue("@product_id", sale->Product_Id);
        cmd->Parameters->AddWithValue("@user_id", safe_cast<Object^>(sale->User_Id));
        cmd->Parameters->AddWithValue("@quantity", sale->Quantity);
        cmd->Parameters->AddWithValue("@total_price", sale->Total_Price);
        cmd->Parameters->AddWithValue("@id", sale->Id);
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("UpdateSale Error", ex);
    }
    finally {
        conn->Close();
    }
}

void SalesController::DeleteSale(int id)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "DELETE FROM sales WHERE id=@id";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("DeleteSale Error", ex);
    }
    finally {
        conn->Close();
    }
}