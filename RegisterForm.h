#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>

#include "includes.h"

using namespace std;

namespace VideoRentalStoreRevised {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(String^ phone)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->Phone = phone;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::TextBox^  firstNameBox;
	private: System::Windows::Forms::TextBox^  lastNameBox;
	private: String^ Phone;



	private: System::Windows::Forms::Button^  button1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->firstNameBox = (gcnew System::Windows::Forms::TextBox());
			this->lastNameBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(36, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"First Name:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(36, 59);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Last Name:";
			// 
			// firstNameBox
			// 
			this->firstNameBox->Location = System::Drawing::Point(125, 30);
			this->firstNameBox->Name = L"firstNameBox";
			this->firstNameBox->Size = System::Drawing::Size(100, 20);
			this->firstNameBox->TabIndex = 4;
			this->firstNameBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RegisterForm::firstNameBox_KeyPress);
			// 
			// lastNameBox
			// 
			this->lastNameBox->Location = System::Drawing::Point(125, 56);
			this->lastNameBox->Name = L"lastNameBox";
			this->lastNameBox->Size = System::Drawing::Size(100, 20);
			this->lastNameBox->TabIndex = 5;
			this->lastNameBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &RegisterForm::lastNameBox_KeyPress);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(125, 82);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Register";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &RegisterForm::button1_Click);
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 129);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->lastNameBox);
			this->Controls->Add(this->firstNameBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"RegisterForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Register";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void firstNameBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar == (wchar_t)Keys::Enter)
			lastNameBox->Focus();
	}
private: System::Void lastNameBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if (e->KeyChar == (wchar_t)Keys::Enter)
	{
		button1->Focus();
		button1->PerformClick();
	}
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	string firstName = marshal_as<string>(firstNameBox->Text);
	string lastName = marshal_as<string>(lastNameBox->Text);
	string phone = marshal_as<string>(Phone->Substring(0));

	store->addCustomer(firstName, lastName, phone);

	MessageBox::Show("Done!", "You are now a member");
	Close();
}
};
}
