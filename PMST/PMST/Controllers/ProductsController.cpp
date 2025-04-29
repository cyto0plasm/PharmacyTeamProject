#include "ProductsController.h"
#include "../Database/DBConnection.h"
#include "../Models/ProductModel.h"
using namespace PMST;
bool ProductsController::CreateProduct(ProductModel^ product)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "INSERT INTO products (pharmacy_id, category_id, supplier_id, name, price, quantity) "
            "VALUES (@pharmacy_id, @category_id, @supplier_id, @name, @price, @quantity)";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@pharmacy_id", product->Pharmacy_Id);
        cmd->Parameters->AddWithValue("@category_id", product->Category_Id);
        cmd->Parameters->AddWithValue("@supplier_id", product->Supplier_Id);
        cmd->Parameters->AddWithValue("@name", product->Name);
        cmd->Parameters->AddWithValue("@price", product->Price);
        cmd->Parameters->AddWithValue("@quantity", product->Quantity);
        return (cmd->ExecuteNonQuery() > 0);
    }
    catch (Exception^ ex) {
        throw gcnew Exception("CreateProduct Error", ex);
    }
    finally {
        conn->Close();
    }
}

List<ProductModel^>^ ProductsController::GetAllProducts()
{
    auto list = gcnew List<ProductModel^>();
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "SELECT * FROM products";
        auto cmd = gcnew MySqlCommand(query, conn);
        auto reader = cmd->ExecuteReader();
        while (reader->Read()) {
            auto m = gcnew ProductModel();
            m->Id = reader->GetInt32("id");
            m->Pharmacy_Id = reader->GetInt32("pharmacy_id");
            m->Category_Id = reader->GetInt32("category_id");
            m->Supplier_Id = reader->GetInt32("supplier_id");
            m->Name = reader->GetString("name");
            m->Price = reader->GetDecimal("price");
            m->Quantity = reader->GetInt32("quantity");
            m->Created_At = reader->GetDateTime("created_at");
            m->Updated_At = reader->GetDateTime("updated_at");
            list->Add(m);
        }
    }
    catch (Exception^ ex) {
        throw gcnew Exception("GetAllProducts Error", ex);
    }
    finally {
        conn->Close();
    }
    return list;
}

void ProductsController::UpdateProduct(ProductModel^ product)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "UPDATE products SET pharmacy_id=@pharmacy_id, category_id=@category_id, "
            "supplier_id=@supplier_id, name=@name, price=@price, quantity=@quantity WHERE id=@id";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@pharmacy_id", product->Pharmacy_Id);
        cmd->Parameters->AddWithValue("@category_id", product->Category_Id);
        cmd->Parameters->AddWithValue("@supplier_id", product->Supplier_Id);
        cmd->Parameters->AddWithValue("@name", product->Name);
        cmd->Parameters->AddWithValue("@price", product->Price);
        cmd->Parameters->AddWithValue("@quantity", product->Quantity);
        cmd->Parameters->AddWithValue("@id", product->Id);
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("UpdateProduct Error", ex);
    }
    finally {
        conn->Close();
    }
}

void ProductsController::DeleteProduct(int id)
{
    auto conn = DBConnection::GetConnection();
    try {
        conn->Open();
        String^ query = "DELETE FROM products WHERE id=@id";
        auto cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        cmd->ExecuteNonQuery();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("DeleteProduct Error", ex);
    }
    finally {
        conn->Close();
    }
}