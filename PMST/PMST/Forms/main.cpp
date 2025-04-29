#include "Dashboard.h"  
#include "../Database/DBConnection.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
int main(array<String^>^ args)
{
	MessageBox::Show("Main started");

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	/*PharmacyManagementSystem::Dashboard^ form = gcnew PharmacyManagementSystem::Dashboard();
	Application::Run(form);*/

	/*try {
		Application::Run(gcnew PMST::Dashboard());
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message);
	}*/

	try
	{
		// 🔥 TEST the database connection first
		MySqlConnection^ testConn = DBConnection::GetConnection();
		testConn->Open(); // Force connect
		testConn->Close(); // Close immediately after checking
		MessageBox::Show("Database connection successful!"); // ✅ Show success
	}
	catch (Exception^ ex)
	{
		
		MessageBox::Show("Database connection FAILED:\n" + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return -1; // Exit the program
	}

	// Only run app if connection is fine
	try
	{
		Application::Run(gcnew PMST::Dashboard());
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Error launching Dashboard: " + ex->Message);
	}


	return 0;
}
