#include "../Controllers/CategoryController.h"  
#include "../Database/DBConnection.h"  
#include "../Models/CategoryModel.h" 
using namespace PMST;  

bool CategoryController::CreateCategory(CategoryModel^ category)  
{  
   MySqlConnection^ conn = DBConnection::GetConnection();  
   try  
   {  
	   conn->Open();  
	   String^ query = "INSERT INTO categories (pharmacy_id, name, description) VALUES (@pharmacy_id, @name, @description)";  
	   MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);  
	   cmd->Parameters->AddWithValue("@pharmacy_id", category->Pharmacy_Id);  
	   cmd->Parameters->AddWithValue("@name", category->Name);  
	   cmd->Parameters->AddWithValue("@description", category->Description);  

	   int rowsAffected = cmd->ExecuteNonQuery();  

	   return (rowsAffected > 0); 
   }  
   catch (Exception^ ex)  
   {  
	   
	   throw gcnew Exception("CreateCategory Error", ex);

	   

	   return false; // ? return false if error happened  
   }  
   finally  
   {  
	   conn->Close();  
   }  
}  

List<PMST::CategoryModel^>^ CategoryController::GetAllCategories()  
{  
   List<PMST::CategoryModel^>^ categories = gcnew List<PMST::CategoryModel^>();  
   MySqlConnection^ conn = DBConnection::GetConnection();  
   try  
   {  
	   conn->Open();  
	   String^ query = "SELECT * FROM categories";  
	   MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);  
	   MySqlDataReader^ reader = cmd->ExecuteReader();  

	   while (reader->Read())  
	   {  
		   PMST::CategoryModel^ cat = gcnew PMST::CategoryModel();  
		   cat->Id = reader->GetInt32("id");  
		   cat->Pharmacy_Id = reader->GetInt32("pharmacy_id");  
		   cat->Name = reader->GetString("name");  
		   cat->Description = reader->IsDBNull(reader->GetOrdinal("description")) ? "" : reader->GetString("description");  
		   cat->Created_At = reader->GetDateTime("created_at");  
		   cat->Updated_At = reader->GetDateTime("updated_at");  
		   categories->Add(cat);  
	   }  
   }  
   catch (Exception^ ex)  
   {  
	   throw gcnew Exception("GetAllCategories Error: " , ex);  
   }  
   finally  
   {  
	   conn->Close();  
   }  
   return categories;  
}  

void CategoryController::UpdateCategory(CategoryModel^ category)  
{  
   MySqlConnection^ conn = DBConnection::GetConnection();  
   try  
   {  
	   conn->Open();  
	   String^ query = "UPDATE categories SET pharmacy_id=@pharmacy_id, name=@name, description=@description WHERE id=@id";  
	   MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);  
	   cmd->Parameters->AddWithValue("@pharmacy_id", category->Pharmacy_Id);  
	   cmd->Parameters->AddWithValue("@name", category->Name);  
	   cmd->Parameters->AddWithValue("@description", category->Description);  
	   cmd->Parameters->AddWithValue("@id", category->Id);  
	   cmd->ExecuteNonQuery();  
   }  
   catch (Exception^ ex)  
   {  
	   throw gcnew Exception("UpdateCategory Error", ex);
   }  
   finally  
   {  
	   conn->Close();  
   }  
}  

void CategoryController::DeleteCategory(int id)  
{  
   MySqlConnection^ conn = DBConnection::GetConnection();  
   try  
   {  
	   conn->Open();  
	   String^ query = "DELETE FROM categories WHERE id=@id";  
	   MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);  
	   cmd->Parameters->AddWithValue("@id", id);  
	   cmd->ExecuteNonQuery();  
   }  
   catch (Exception^ ex)  
   {  
	   throw gcnew Exception("DeleteCategory Error: " , ex);  
   }  
   finally  
   {  
	   conn->Close();  
   }  
}
