
#include "Dashboard.h"
using namespace PMST;
Dashboard::Dashboard(void)
{
	InitializeComponent(); // Always first
	resources = gcnew System::ComponentModel::ComponentResourceManager(Dashboard::typeid);



	// Save the original image and create resized versions
	originalUserImage = this->userBtn->Image; // Original from resources
	collapsedUserImage = ResizeImage(originalUserImage, 48, 48); // Smaller size
	expandedUserImage = ResizeImage(originalUserImage, 65, 65);  // Larger size
	this->maximizeIcon = (resources->GetObject(L"max2") != nullptr) ?
		cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"max2")) :
		nullptr;

	this->minimizeIcon = (resources->GetObject(L"min2") != nullptr) ?
		cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"min2")) :
		nullptr;

	// Set initial image
	if (this->maximizeIcon != nullptr) {
		this->minMax->Image = this->maximizeIcon;
	}
}