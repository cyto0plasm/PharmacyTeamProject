#pragma once

namespace PMST {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Dashboard
	/// </summary>
	public ref class Dashboard : public System::Windows::Forms::Form
	{
	public:
		Dashboard(void)
		{
			resources = gcnew System::ComponentModel::ComponentResourceManager(Dashboard::typeid);

			InitializeComponent();
			// Save the original image and create resized versions
			originalUserImage = this->userBtn->Image; // Original from resources
			collapsedUserImage = ResizeImage(originalUserImage, 48,48); // Smaller size
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
	protected:
	private:
	 System::Windows::Forms::Panel^ infoPanel;
	 System::Windows::Forms::Panel^ panel1;
	 System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	 System::Windows::Forms::Panel^ panel2;
	 System::Windows::Forms::FlowLayoutPanel^ flowMainPanel;
	 System::Windows::Forms::Button^ category;
	 System::Windows::Forms::Button^ supplier;
	 System::Windows::Forms::Button^ product;
	 System::Windows::Forms::Panel^ Header;
	 System::Windows::Forms::Panel^ FooterPanel;
	 System::Windows::Forms::Panel^ RightPanel;
	 System::Windows::Forms::FlowLayoutPanel^ NavPanel;
	 System::Windows::Forms::Panel^ UserPanel;
	private: System::Windows::Forms::Panel^ CenterPanel;

	 System::Windows::Forms::Button^ homeBtn;
	 System::Windows::Forms::Button^ cashierBtn;
	 System::Windows::Forms::Button^ productBtn;
	 System::Windows::Forms::Button^ categoryBtn;
	 System::Windows::Forms::Button^ supplierBtn;
	 System::Windows::Forms::Button^ stockBtn;
	 System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ logo;

	 System::Windows::Forms::Button^ close;
	 System::Windows::Forms::Button^ minMax;
	 System::Windows::Forms::Button^ minimize;
	 System::Windows::Forms::Button^ collaps;
	System::Drawing::Image^ maximizeIcon;
	System::Drawing::Image^ minimizeIcon;
	System::ComponentModel::ComponentResourceManager^ resources; 
	System::Windows::Forms::Button^ userBtn;
	System::Drawing::Image^ originalUserImage;
	System::Drawing::Image^ collapsedUserImage;
	System::Drawing::Image^ expandedUserImage;
	private: System::Windows::Forms::Panel^ HomePanel;

	private: System::Windows::Forms::Panel^ CashierPanel;
	private: System::Windows::Forms::Panel^ StockPanel;
	private: System::Windows::Forms::Panel^ SupplierPanel;
	private: System::Windows::Forms::Panel^ ProductPanel;
	private: System::Windows::Forms::Panel^ CategoryPanel;
	private: System::Windows::Forms::Label^ pharmacyNameLabel;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ pharmacyName;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ expandBtn;
	private: System::Windows::Forms::Button^ totalSales;
	private: System::Windows::Forms::FlowLayoutPanel^ fastNav;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;












		   //DATABASE
	private:
		System::String^ userName;
		//UTILS FUNCTIONS
	private:
		Bitmap^ ResizeImage(Image^ image, int maxWidth, int maxHeight) {
			double ratioX = (double)maxWidth / image->Width;
			double ratioY = (double)maxHeight / image->Height;
			double ratio = Math::Min(ratioX, ratioY);

			int newWidth = (int)(image->Width * ratio);
			int newHeight = (int)(image->Height * ratio);

			Bitmap^ resizedImage = gcnew Bitmap(newWidth, newHeight);
			Graphics^ g = Graphics::FromImage(resizedImage);
			g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::HighQualityBicubic;
			g->DrawImage(image, 0, 0, newWidth, newHeight);
			delete g;
			return resizedImage;
		}





	private: System::Windows::Forms::Button^ cashier;

		
		~Dashboard()
		{
			if (components)
			{
				delete components;
			}
			if (maximizeIcon) delete maximizeIcon;
			if (minimizeIcon) delete minimizeIcon;
		}

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		


		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Dashboard::typeid));
			this->Header = (gcnew System::Windows::Forms::Panel());
			this->minMax = (gcnew System::Windows::Forms::Button());
			this->minimize = (gcnew System::Windows::Forms::Button());
			this->close = (gcnew System::Windows::Forms::Button());
			this->logo = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->FooterPanel = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pharmacyName = (gcnew System::Windows::Forms::Label());
			this->pharmacyNameLabel = (gcnew System::Windows::Forms::Label());
			this->RightPanel = (gcnew System::Windows::Forms::Panel());
			this->NavPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->homeBtn = (gcnew System::Windows::Forms::Button());
			this->cashierBtn = (gcnew System::Windows::Forms::Button());
			this->productBtn = (gcnew System::Windows::Forms::Button());
			this->categoryBtn = (gcnew System::Windows::Forms::Button());
			this->supplierBtn = (gcnew System::Windows::Forms::Button());
			this->stockBtn = (gcnew System::Windows::Forms::Button());
			this->UserPanel = (gcnew System::Windows::Forms::Panel());
			this->userBtn = (gcnew System::Windows::Forms::Button());
			this->collaps = (gcnew System::Windows::Forms::Button());
			this->expandBtn = (gcnew System::Windows::Forms::Button());
			this->CenterPanel = (gcnew System::Windows::Forms::Panel());
			this->HomePanel = (gcnew System::Windows::Forms::Panel());
			this->fastNav = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->totalSales = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->StockPanel = (gcnew System::Windows::Forms::Panel());
			this->SupplierPanel = (gcnew System::Windows::Forms::Panel());
			this->ProductPanel = (gcnew System::Windows::Forms::Panel());
			this->CategoryPanel = (gcnew System::Windows::Forms::Panel());
			this->CashierPanel = (gcnew System::Windows::Forms::Panel());
			this->Header->SuspendLayout();
			this->FooterPanel->SuspendLayout();
			this->RightPanel->SuspendLayout();
			this->NavPanel->SuspendLayout();
			this->UserPanel->SuspendLayout();
			this->CenterPanel->SuspendLayout();
			this->HomePanel->SuspendLayout();
			this->fastNav->SuspendLayout();
			this->SuspendLayout();
			// 
			// Header
			// 
			this->Header->AccessibleName = L"headerPanel";
			this->Header->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Header->Controls->Add(this->minMax);
			this->Header->Controls->Add(this->minimize);
			this->Header->Controls->Add(this->close);
			this->Header->Controls->Add(this->logo);
			this->Header->Controls->Add(this->label1);
			this->Header->Dock = System::Windows::Forms::DockStyle::Top;
			this->Header->Location = System::Drawing::Point(0, 0);
			this->Header->Name = L"Header";
			this->Header->Size = System::Drawing::Size(1488, 68);
			this->Header->TabIndex = 0;
			// 
			// minMax
			// 
			this->minMax->AccessibleName = L"cashierBtn";
			this->minMax->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->minMax->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->minMax->FlatAppearance->BorderSize = 0;
			this->minMax->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->minMax->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->minMax->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"minMax.Image")));
			this->minMax->Location = System::Drawing::Point(1422, 18);
			this->minMax->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->minMax->Name = L"minMax";
			this->minMax->Size = System::Drawing::Size(24, 24);
			this->minMax->TabIndex = 3;
			this->minMax->UseVisualStyleBackColor = false;
			this->minMax->Click += gcnew System::EventHandler(this, &Dashboard::button5_Click_1);
			// 
			// minimize
			// 
			this->minimize->AccessibleName = L"cashierBtn";
			this->minimize->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->minimize->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->minimize->FlatAppearance->BorderSize = 0;
			this->minimize->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->minimize->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->minimize->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"minimize.Image")));
			this->minimize->Location = System::Drawing::Point(1392, 18);
			this->minimize->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->minimize->Name = L"minimize";
			this->minimize->Size = System::Drawing::Size(24, 24);
			this->minimize->TabIndex = 3;
			this->minimize->UseVisualStyleBackColor = false;
			this->minimize->Click += gcnew System::EventHandler(this, &Dashboard::minimize_Click);
			// 
			// close
			// 
			this->close->AccessibleName = L"close";
			this->close->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->close->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->close->FlatAppearance->BorderSize = 0;
			this->close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->close->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->close->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"close.Image")));
			this->close->Location = System::Drawing::Point(1453, 18);
			this->close->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->close->Name = L"close";
			this->close->Size = System::Drawing::Size(24, 24);
			this->close->TabIndex = 3;
			this->close->UseVisualStyleBackColor = false;
			this->close->Click += gcnew System::EventHandler(this, &Dashboard::button4_Click);
			// 
			// logo
			// 
			this->logo->AutoSize = true;
			this->logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logo.Image")));
			this->logo->Location = System::Drawing::Point(9, 6);
			this->logo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->logo->MaximumSize = System::Drawing::Size(0, 64);
			this->logo->MinimumSize = System::Drawing::Size(200, 16);
			this->logo->Name = L"logo";
			this->logo->Padding = System::Windows::Forms::Padding(32, 28, 56, 28);
			this->logo->Size = System::Drawing::Size(200, 64);
			this->logo->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AccessibleName = L"AppTitle";
			this->label1->AutoSize = true;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(456, 18);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L" ...مدير الصيدلية";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// FooterPanel
			// 
			this->FooterPanel->AccessibleName = L"FooterPanel";
			this->FooterPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->FooterPanel->Controls->Add(this->label4);
			this->FooterPanel->Controls->Add(this->label3);
			this->FooterPanel->Controls->Add(this->pharmacyName);
			this->FooterPanel->Controls->Add(this->pharmacyNameLabel);
			this->FooterPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->FooterPanel->Location = System::Drawing::Point(0, 619);
			this->FooterPanel->Name = L"FooterPanel";
			this->FooterPanel->Size = System::Drawing::Size(1488, 87);
			this->FooterPanel->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AccessibleName = L"pharmacyName";
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Silver;
			this->label4->Location = System::Drawing::Point(7, 38);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(158, 20);
			this->label4->TabIndex = 0;
			this->label4->Text = L"All rights reserved.";
			this->label4->Click += gcnew System::EventHandler(this, &Dashboard::pharmacyName_Click);
			// 
			// label3
			// 
			this->label3->AccessibleName = L"pharmacyName";
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Silver;
			this->label3->Location = System::Drawing::Point(2, 15);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(255, 20);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Copyright © 2025 Cyto0plasm .";
			this->label3->Click += gcnew System::EventHandler(this, &Dashboard::pharmacyName_Click);
			// 
			// pharmacyName
			// 
			this->pharmacyName->AccessibleName = L"pharmacyName";
			this->pharmacyName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->pharmacyName->AutoSize = true;
			this->pharmacyName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pharmacyName->ForeColor = System::Drawing::Color::Lime;
			this->pharmacyName->Location = System::Drawing::Point(1177, 26);
			this->pharmacyName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->pharmacyName->Name = L"pharmacyName";
			this->pharmacyName->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->pharmacyName->Size = System::Drawing::Size(149, 31);
			this->pharmacyName->TabIndex = 0;
			this->pharmacyName->Text = L"صيدلية الشفاء";
			this->pharmacyName->Click += gcnew System::EventHandler(this, &Dashboard::pharmacyName_Click);
			// 
			// pharmacyNameLabel
			// 
			this->pharmacyNameLabel->AccessibleName = L"pharmacyNameLabel";
			this->pharmacyNameLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->pharmacyNameLabel->AutoSize = true;
			this->pharmacyNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pharmacyNameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->pharmacyNameLabel->Location = System::Drawing::Point(1316, 26);
			this->pharmacyNameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->pharmacyNameLabel->Name = L"pharmacyNameLabel";
			this->pharmacyNameLabel->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->pharmacyNameLabel->Size = System::Drawing::Size(155, 31);
			this->pharmacyNameLabel->TabIndex = 0;
			this->pharmacyNameLabel->Text = L"اسم الصيدلية: ";
			this->pharmacyNameLabel->Click += gcnew System::EventHandler(this, &Dashboard::pharmacyName_Click);
			// 
			// RightPanel
			// 
			this->RightPanel->AccessibleName = L"RightPanel";
			this->RightPanel->Controls->Add(this->NavPanel);
			this->RightPanel->Controls->Add(this->UserPanel);
			this->RightPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->RightPanel->Location = System::Drawing::Point(1280, 68);
			this->RightPanel->MaximumSize = System::Drawing::Size(208, 552);
			this->RightPanel->MinimumSize = System::Drawing::Size(56, 552);
			this->RightPanel->Name = L"RightPanel";
			this->RightPanel->Size = System::Drawing::Size(208, 552);
			this->RightPanel->TabIndex = 2;
			// 
			// NavPanel
			// 
			this->NavPanel->AccessibleName = L"NavPanel";
			this->NavPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->NavPanel->Controls->Add(this->homeBtn);
			this->NavPanel->Controls->Add(this->cashierBtn);
			this->NavPanel->Controls->Add(this->productBtn);
			this->NavPanel->Controls->Add(this->categoryBtn);
			this->NavPanel->Controls->Add(this->supplierBtn);
			this->NavPanel->Controls->Add(this->stockBtn);
			this->NavPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->NavPanel->Location = System::Drawing::Point(0, 117);
			this->NavPanel->MaximumSize = System::Drawing::Size(236, 569);
			this->NavPanel->Name = L"NavPanel";
			this->NavPanel->Size = System::Drawing::Size(208, 435);
			this->NavPanel->TabIndex = 1;
			// 
			// homeBtn
			// 
			this->homeBtn->AccessibleName = L"homeBtn";
			this->homeBtn->AutoEllipsis = true;
			this->homeBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->homeBtn->FlatAppearance->BorderSize = 0;
			this->homeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->homeBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->homeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"homeBtn.Image")));
			this->homeBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->homeBtn->Location = System::Drawing::Point(3, 5);
			this->homeBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->homeBtn->MaximumSize = System::Drawing::Size(200, 64);
			this->homeBtn->MinimumSize = System::Drawing::Size(64, 64);
			this->homeBtn->Name = L"homeBtn";
			this->homeBtn->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
			this->homeBtn->Size = System::Drawing::Size(200, 64);
			this->homeBtn->TabIndex = 1;
			this->homeBtn->Text = L"الرئيسية";
			this->homeBtn->UseVisualStyleBackColor = false;
			this->homeBtn->Click += gcnew System::EventHandler(this, &Dashboard::homeBtn_Click);
			// 
			// cashierBtn
			// 
			this->cashierBtn->AccessibleName = L"cashierBtn";
			this->cashierBtn->AutoEllipsis = true;
			this->cashierBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->cashierBtn->FlatAppearance->BorderSize = 0;
			this->cashierBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cashierBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->cashierBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cashierBtn.Image")));
			this->cashierBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->cashierBtn->Location = System::Drawing::Point(3, 77);
			this->cashierBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->cashierBtn->MaximumSize = System::Drawing::Size(200, 64);
			this->cashierBtn->MinimumSize = System::Drawing::Size(64, 64);
			this->cashierBtn->Name = L"cashierBtn";
			this->cashierBtn->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
			this->cashierBtn->Size = System::Drawing::Size(200, 64);
			this->cashierBtn->TabIndex = 2;
			this->cashierBtn->Text = L"كاشير";
			this->cashierBtn->UseVisualStyleBackColor = false;
			this->cashierBtn->Click += gcnew System::EventHandler(this, &Dashboard::cashierBtn_Click);
			// 
			// productBtn
			// 
			this->productBtn->AccessibleName = L"productBtn";
			this->productBtn->AutoEllipsis = true;
			this->productBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->productBtn->FlatAppearance->BorderSize = 0;
			this->productBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->productBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->productBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"productBtn.Image")));
			this->productBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->productBtn->Location = System::Drawing::Point(3, 149);
			this->productBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->productBtn->MaximumSize = System::Drawing::Size(200, 64);
			this->productBtn->MinimumSize = System::Drawing::Size(64, 64);
			this->productBtn->Name = L"productBtn";
			this->productBtn->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
			this->productBtn->Size = System::Drawing::Size(200, 64);
			this->productBtn->TabIndex = 3;
			this->productBtn->Text = L"المنتجات";
			this->productBtn->UseVisualStyleBackColor = false;
			this->productBtn->Click += gcnew System::EventHandler(this, &Dashboard::productBtn_Click);
			// 
			// categoryBtn
			// 
			this->categoryBtn->AccessibleName = L"categoryBtn";
			this->categoryBtn->AutoEllipsis = true;
			this->categoryBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->categoryBtn->FlatAppearance->BorderSize = 0;
			this->categoryBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->categoryBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->categoryBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"categoryBtn.Image")));
			this->categoryBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->categoryBtn->Location = System::Drawing::Point(3, 221);
			this->categoryBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->categoryBtn->MaximumSize = System::Drawing::Size(200, 64);
			this->categoryBtn->MinimumSize = System::Drawing::Size(64, 64);
			this->categoryBtn->Name = L"categoryBtn";
			this->categoryBtn->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
			this->categoryBtn->Size = System::Drawing::Size(200, 64);
			this->categoryBtn->TabIndex = 4;
			this->categoryBtn->Text = L"الاصناف";
			this->categoryBtn->UseVisualStyleBackColor = false;
			this->categoryBtn->Click += gcnew System::EventHandler(this, &Dashboard::categoryBtn_Click);
			// 
			// supplierBtn
			// 
			this->supplierBtn->AccessibleName = L"supplierBtn";
			this->supplierBtn->AutoEllipsis = true;
			this->supplierBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->supplierBtn->FlatAppearance->BorderSize = 0;
			this->supplierBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->supplierBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->supplierBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"supplierBtn.Image")));
			this->supplierBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->supplierBtn->Location = System::Drawing::Point(3, 293);
			this->supplierBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->supplierBtn->MaximumSize = System::Drawing::Size(200, 64);
			this->supplierBtn->MinimumSize = System::Drawing::Size(64, 64);
			this->supplierBtn->Name = L"supplierBtn";
			this->supplierBtn->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
			this->supplierBtn->Size = System::Drawing::Size(200, 64);
			this->supplierBtn->TabIndex = 5;
			this->supplierBtn->Text = L"الموردين";
			this->supplierBtn->UseVisualStyleBackColor = false;
			this->supplierBtn->Click += gcnew System::EventHandler(this, &Dashboard::supplierBtn_Click);
			// 
			// stockBtn
			// 
			this->stockBtn->AccessibleName = L"stockBtn";
			this->stockBtn->AutoEllipsis = true;
			this->stockBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->stockBtn->FlatAppearance->BorderSize = 0;
			this->stockBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->stockBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->stockBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"stockBtn.Image")));
			this->stockBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->stockBtn->Location = System::Drawing::Point(3, 365);
			this->stockBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->stockBtn->MaximumSize = System::Drawing::Size(200, 64);
			this->stockBtn->MinimumSize = System::Drawing::Size(64, 64);
			this->stockBtn->Name = L"stockBtn";
			this->stockBtn->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
			this->stockBtn->Size = System::Drawing::Size(200, 64);
			this->stockBtn->TabIndex = 6;
			this->stockBtn->Text = L"المخزون";
			this->stockBtn->UseVisualStyleBackColor = false;
			this->stockBtn->Click += gcnew System::EventHandler(this, &Dashboard::stockBtn_Click);
			// 
			// UserPanel
			// 
			this->UserPanel->AccessibleName = L"UserPanel";
			this->UserPanel->Controls->Add(this->userBtn);
			this->UserPanel->Controls->Add(this->collaps);
			this->UserPanel->Controls->Add(this->expandBtn);
			this->UserPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->UserPanel->Location = System::Drawing::Point(0, 0);
			this->UserPanel->Name = L"UserPanel";
			this->UserPanel->Size = System::Drawing::Size(208, 117);
			this->UserPanel->TabIndex = 0;
			// 
			// userBtn
			// 
			this->userBtn->AccessibleName = L"userBtn";
			this->userBtn->AutoEllipsis = true;
			this->userBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->userBtn->FlatAppearance->BorderSize = 0;
			this->userBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->userBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->userBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"userBtn.Image")));
			this->userBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->userBtn->Location = System::Drawing::Point(4, 34);
			this->userBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->userBtn->MaximumSize = System::Drawing::Size(200, 77);
			this->userBtn->MinimumSize = System::Drawing::Size(64, 77);
			this->userBtn->Name = L"userBtn";
			this->userBtn->Padding = System::Windows::Forms::Padding(0, 0, 8, 0);
			this->userBtn->Size = System::Drawing::Size(200, 77);
			this->userBtn->TabIndex = 5;
			this->userBtn->Text = L"اسم المستخدم";
			this->userBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->userBtn->UseVisualStyleBackColor = false;
			// 
			// collaps
			// 
			this->collaps->AccessibleName = L"collapsBtn";
			this->collaps->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->collaps->FlatAppearance->BorderSize = 0;
			this->collaps->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->collaps->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->collaps->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"collaps.Image")));
			this->collaps->Location = System::Drawing::Point(15, 8);
			this->collaps->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->collaps->Name = L"collaps";
			this->collaps->Size = System::Drawing::Size(24, 24);
			this->collaps->TabIndex = 3;
			this->collaps->UseVisualStyleBackColor = false;
			this->collaps->Click += gcnew System::EventHandler(this, &Dashboard::collaps_Click);
			// 
			// expandBtn
			// 
			this->expandBtn->AccessibleName = L"expandBtn";
			this->expandBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->expandBtn->FlatAppearance->BorderSize = 0;
			this->expandBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->expandBtn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold));
			this->expandBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"expandBtn.Image")));
			this->expandBtn->Location = System::Drawing::Point(15, 8);
			this->expandBtn->Margin = System::Windows::Forms::Padding(3, 5, 3, 3);
			this->expandBtn->Name = L"expandBtn";
			this->expandBtn->Size = System::Drawing::Size(24, 24);
			this->expandBtn->TabIndex = 3;
			this->expandBtn->UseVisualStyleBackColor = false;
			this->expandBtn->Click += gcnew System::EventHandler(this, &Dashboard::collaps_Click);
			// 
			// CenterPanel
			// 
			this->CenterPanel->AccessibleName = L"Home";
			this->CenterPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CenterPanel->Controls->Add(this->HomePanel);
			this->CenterPanel->Controls->Add(this->StockPanel);
			this->CenterPanel->Controls->Add(this->SupplierPanel);
			this->CenterPanel->Controls->Add(this->ProductPanel);
			this->CenterPanel->Controls->Add(this->CategoryPanel);
			this->CenterPanel->Controls->Add(this->CashierPanel);
			this->CenterPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CenterPanel->Location = System::Drawing::Point(0, 68);
			this->CenterPanel->Name = L"CenterPanel";
			this->CenterPanel->Size = System::Drawing::Size(1280, 551);
			this->CenterPanel->TabIndex = 3;
			// 
			// HomePanel
			// 
			this->HomePanel->Controls->Add(this->fastNav);
			this->HomePanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->HomePanel->Location = System::Drawing::Point(0, 0);
			this->HomePanel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HomePanel->Name = L"HomePanel";
			this->HomePanel->Size = System::Drawing::Size(1278, 549);
			this->HomePanel->TabIndex = 0;
			// 
			// fastNav
			// 
			this->fastNav->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->fastNav->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->fastNav->Controls->Add(this->totalSales);
			this->fastNav->Controls->Add(this->button1);
			this->fastNav->Controls->Add(this->button2);
			this->fastNav->Controls->Add(this->button3);
			this->fastNav->Dock = System::Windows::Forms::DockStyle::Top;
			this->fastNav->Location = System::Drawing::Point(0, 0);
			this->fastNav->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->fastNav->Name = L"fastNav";
			this->fastNav->Padding = System::Windows::Forms::Padding(95, 5, 90, 5);
			this->fastNav->Size = System::Drawing::Size(1278, 98);
			this->fastNav->TabIndex = 1;
			// 
			// totalSales
			// 
			this->totalSales->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->totalSales->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->totalSales->FlatAppearance->BorderSize = 0;
			this->totalSales->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->totalSales->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totalSales->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->totalSales->Location = System::Drawing::Point(97, 7);
			this->totalSales->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->totalSales->Name = L"totalSales";
			this->totalSales->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->totalSales->Size = System::Drawing::Size(266, 83);
			this->totalSales->TabIndex = 0;
			this->totalSales->Text = L"إجمالي المبيعات اليوم";
			this->totalSales->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->totalSales->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button1->Location = System::Drawing::Point(367, 7);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button1->Size = System::Drawing::Size(266, 83);
			this->button1->TabIndex = 0;
			this->button1->Text = L"عدد المنتجات المباعة";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button2->Location = System::Drawing::Point(637, 7);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button2->Size = System::Drawing::Size(266, 83);
			this->button2->TabIndex = 0;
			this->button2->Text = L"اكثر صنف مبيعا";
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->button3->Location = System::Drawing::Point(907, 7);
			this->button3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button3->Name = L"button3";
			this->button3->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button3->Size = System::Drawing::Size(266, 83);
			this->button3->TabIndex = 0;
			this->button3->Text = L"المورد المتميز";
			this->button3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->UseVisualStyleBackColor = true;
			// 
			// StockPanel
			// 
			this->StockPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->StockPanel->Location = System::Drawing::Point(0, 0);
			this->StockPanel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->StockPanel->Name = L"StockPanel";
			this->StockPanel->Size = System::Drawing::Size(1278, 549);
			this->StockPanel->TabIndex = 5;
			// 
			// SupplierPanel
			// 
			this->SupplierPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->SupplierPanel->Location = System::Drawing::Point(0, 0);
			this->SupplierPanel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->SupplierPanel->Name = L"SupplierPanel";
			this->SupplierPanel->Size = System::Drawing::Size(1278, 549);
			this->SupplierPanel->TabIndex = 4;
			// 
			// ProductPanel
			// 
			this->ProductPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ProductPanel->Location = System::Drawing::Point(0, 0);
			this->ProductPanel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ProductPanel->Name = L"ProductPanel";
			this->ProductPanel->Size = System::Drawing::Size(1278, 549);
			this->ProductPanel->TabIndex = 3;
			// 
			// CategoryPanel
			// 
			this->CategoryPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CategoryPanel->Location = System::Drawing::Point(0, 0);
			this->CategoryPanel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->CategoryPanel->Name = L"CategoryPanel";
			this->CategoryPanel->Size = System::Drawing::Size(1278, 549);
			this->CategoryPanel->TabIndex = 2;
			// 
			// CashierPanel
			// 
			this->CashierPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CashierPanel->Location = System::Drawing::Point(0, 0);
			this->CashierPanel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->CashierPanel->Name = L"CashierPanel";
			this->CashierPanel->Size = System::Drawing::Size(1278, 549);
			this->CashierPanel->TabIndex = 1;
			// 
			// Dashboard
			// 
			this->AccessibleName = L"DashboardFrame";
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ClientSize = System::Drawing::Size(1488, 706);
			this->Controls->Add(this->CenterPanel);
			this->Controls->Add(this->RightPanel);
			this->Controls->Add(this->FooterPanel);
			this->Controls->Add(this->Header);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Dashboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dashboard";
			this->Header->ResumeLayout(false);
			this->Header->PerformLayout();
			this->FooterPanel->ResumeLayout(false);
			this->FooterPanel->PerformLayout();
			this->RightPanel->ResumeLayout(false);
			this->NavPanel->ResumeLayout(false);
			this->UserPanel->ResumeLayout(false);
			this->CenterPanel->ResumeLayout(false);
			this->HomePanel->ResumeLayout(false);
			this->fastNav->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
	}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->WindowState == System::Windows::Forms::FormWindowState::Normal)
	{
		this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
	}
	else
	{
		this->WindowState = System::Windows::Forms::FormWindowState::Normal;
	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	// Close the application
	//this->Close();
	//Environment::Exit(0);
	Application::Exit();
}

private: System::Void button5_Click_1(System::Object^ sender, System::EventArgs^ e) {  
	if (this->WindowState == FormWindowState::Normal) {
		this->WindowState = FormWindowState::Maximized;
		if (this->minimizeIcon != nullptr) {
			//this->minMax->Image = this->minimizeIcon;
		}
	}
	else {
		this->WindowState = FormWindowState::Normal;
		if (this->maximizeIcon != nullptr) {
			//this->minMax->Image = this->maximizeIcon;
		}
	}
this->minMax->Refresh();

}
private: System::Void minimize_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->WindowState == FormWindowState::Normal) {
		this->WindowState = FormWindowState::Minimized;
	}
	else {
		this->WindowState = FormWindowState::Normal;
	}
	this->minMax->Refresh();
}

	   private: System::Void collaps_Click(System::Object^ sender, System::EventArgs^ e) {
		   if (this->RightPanel->Width > 200) {
			   this->RightPanel->Width = 70;
			   array<Button^>^ navButtons = {
				  homeBtn, cashierBtn, productBtn,
				  categoryBtn, supplierBtn, stockBtn
			   };

			   for each (Button ^ btn in navButtons) {
				   btn->Text = "";
				   btn->ImageAlign = ContentAlignment::MiddleCenter;
				   btn->Padding = System::Windows::Forms::Padding(0);
				   btn->Width = 45; // Set fixed width for collapsed state
			   }
			   userBtn->Image = collapsedUserImage;
			   userBtn->ImageAlign = ContentAlignment::MiddleLeft; // Center image when collapsed
			   userBtn->TextImageRelation = TextImageRelation::ImageBeforeText;
			   userBtn->Text = "";

			   collaps->SendToBack();

		   }
		   else {
			   this->RightPanel->Width = 260;
			   homeBtn->Text = L"الرئيسية";
			   cashierBtn->Text = L"كاشير";
			   productBtn->Text = L"المنتجات";
			   categoryBtn->Text = L"الاصناف";
			   supplierBtn->Text = L"الموردين";
			   stockBtn->Text = L"المخزون";
			   array<Button^>^ navButtons = {
				  homeBtn, cashierBtn, productBtn,
				  categoryBtn, supplierBtn, stockBtn
			   };

			   for each (Button ^ btn in navButtons) {
				   btn->ImageAlign = ContentAlignment::MiddleRight;
				   btn->Padding = System::Windows::Forms::Padding(0, 0, 10, 0);
				   btn->Width = 280; // Restore original width
			   }
			   userBtn->Image = expandedUserImage;
			   userBtn->ImageAlign = ContentAlignment::MiddleRight; // Align right when expanded
			   userBtn->TextImageRelation = TextImageRelation::TextBeforeImage;
			   //userBtn->Text = userName->IsNullOrEmpty?"اسم المستخدم": userName;
			   userBtn->Text = L"اسم المستخدم";
			   collaps->BringToFront();
		   }
		   this->RightPanel->Refresh();
	   }

private: System::Void homeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	HomePanel->BringToFront();
}
private: System::Void cashierBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	CashierPanel->BringToFront();
}
private: System::Void productBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	ProductPanel->BringToFront();
}
private: System::Void categoryBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	CategoryPanel->BringToFront();
}
private: System::Void supplierBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	SupplierPanel->BringToFront();
}
private: System::Void stockBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	StockPanel->BringToFront();
}
private: System::Void pharmacyName_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
