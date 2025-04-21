#include "Dashboard.h"  

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
	try {
		Application::Run(gcnew PMST::Dashboard());
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message);
	}


	return 0;
}
