#pragma once

namespace PMST {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label6;
	protected:
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ saveCategoryBtn;
	private: System::Windows::Forms::TextBox^ descriptionFeild;
	private: System::Windows::Forms::TextBox^ nameFeild;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->saveCategoryBtn = (gcnew System::Windows::Forms::Button());
			this->descriptionFeild = (gcnew System::Windows::Forms::TextBox());
			this->nameFeild = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(226, 186);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(66, 16);
			this->label6->TabIndex = 6;
			this->label6->Text = L"password";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(226, 118);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 16);
			this->label5->TabIndex = 7;
			this->label5->Text = L"email";
			// 
			// saveCategoryBtn
			// 
			this->saveCategoryBtn->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->saveCategoryBtn->Location = System::Drawing::Point(294, 276);
			this->saveCategoryBtn->Name = L"saveCategoryBtn";
			this->saveCategoryBtn->Size = System::Drawing::Size(101, 30);
			this->saveCategoryBtn->TabIndex = 5;
			this->saveCategoryBtn->Text = L"Save ";
			this->saveCategoryBtn->UseVisualStyleBackColor = true;
			// 
			// descriptionFeild
			// 
			this->descriptionFeild->Location = System::Drawing::Point(217, 218);
			this->descriptionFeild->Name = L"descriptionFeild";
			this->descriptionFeild->Size = System::Drawing::Size(254, 22);
			this->descriptionFeild->TabIndex = 3;
			// 
			// nameFeild
			// 
			this->nameFeild->Location = System::Drawing::Point(217, 149);
			this->nameFeild->Name = L"nameFeild";
			this->nameFeild->Size = System::Drawing::Size(254, 22);
			this->nameFeild->TabIndex = 4;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(217, 80);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(254, 22);
			this->textBox1->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(226, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 16);
			this->label1->TabIndex = 7;
			this->label1->Text = L"name";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(688, 425);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->saveCategoryBtn);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->descriptionFeild);
			this->Controls->Add(this->nameFeild);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
