#pragma once
#include <msclr\marshal_cppstd.h>
#include "includes.h"
#include "RegisterForm.h"
#include "VideoRentalStoreForm.h"

namespace VideoRentalStoreRevised {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
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
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  phoneNumberBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;











	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->phoneNumberBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// phoneNumberBox
			// 
			this->phoneNumberBox->Location = System::Drawing::Point(105, 43);
			this->phoneNumberBox->MaxLength = 10;
			this->phoneNumberBox->Name = L"phoneNumberBox";
			this->phoneNumberBox->Size = System::Drawing::Size(100, 20);
			this->phoneNumberBox->TabIndex = 0;
			this->phoneNumberBox->TextChanged += gcnew System::EventHandler(this, &LoginForm::phoneNumberBox_TextChanged);
			this->phoneNumberBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &LoginForm::phoneNumberBox_KeyDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Phone Number:";
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(225, 38);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 28);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Enter";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LoginForm::button1_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(329, 112);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->phoneNumberBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void phoneNumberBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (!Char::IsNumber((wchar_t)e->KeyCode) && e->KeyCode != Keys::Back && !e->Control && e->KeyCode != Keys::Left && e->KeyCode != Keys::Right
			&& e->KeyCode != Keys::Up && e->KeyCode != Keys::Down && !(e->KeyCode >= Keys::NumPad0 && e->KeyCode <= Keys::NumPad9) && e->KeyCode != Keys::Enter)
		{
			Help::ShowPopup(phoneNumberBox, "Digits only", PointToScreen(Point(phoneNumberBox->Location.X, phoneNumberBox->Location.Y + 20)));
			e->SuppressKeyPress = true;
		}

		else if (e->KeyCode == Keys::Enter)
		{
			button1->Focus();
			button1->PerformClick();
		}
	}
	private: System::Void phoneNumberBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (phoneNumberBox->TextLength == 10 && !button1->Enabled)
			button1->Enabled = true;

		else if (phoneNumberBox->TextLength != 10)
			button1->Enabled = false;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		string phone = marshal_as<string>(phoneNumberBox->Text);

		phoneNumberBox->Text = "";

		if (!store->findCustomer(phone))
		{
			if (MessageBox::Show("Sign up now?", "You are not a member", MessageBoxButtons::YesNo) == ::DialogResult::Yes)
			{
				RegisterForm^ registerForm = gcnew RegisterForm(gcnew String(phone.c_str()));
				registerForm->ShowDialog();
			}

			return;
		}

		customerPhoneNumber = phone;
		Hide();
		VideoRentalStoreForm^ videoRentalStoreForm = gcnew VideoRentalStoreForm();
		videoRentalStoreForm->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &VideoRentalStoreRevised::LoginForm::OnFormClosed);
		videoRentalStoreForm->Show();
	}
	private: void OnFormClosed(Object^ sender, FormClosedEventArgs^ e)
	{
		Show();
	}
};
}
