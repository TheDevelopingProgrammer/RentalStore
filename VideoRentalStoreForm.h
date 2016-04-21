#pragma once
#include "includes.h"

namespace VideoRentalStoreRevised {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for VideoRentalStoreForm
	/// </summary>
	public ref class VideoRentalStoreForm : public System::Windows::Forms::Form
	{
	public:
		VideoRentalStoreForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			updateRentalItemsListBox();
			updateRentedMoviesListBox();
			updateCustomerInfoBox();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VideoRentalStoreForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  rentalItemsListBox;
	private: System::Windows::Forms::RichTextBox^  rentalItemDescriptionBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ListBox^  rentedMoviesListBox;
	private: System::Windows::Forms::Button^  rentButton;
	private: System::Windows::Forms::Button^  returnButton;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::RichTextBox^  customerInfoBox;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VideoRentalStoreForm::typeid));
			this->rentalItemsListBox = (gcnew System::Windows::Forms::ListBox());
			this->rentalItemDescriptionBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->rentedMoviesListBox = (gcnew System::Windows::Forms::ListBox());
			this->rentButton = (gcnew System::Windows::Forms::Button());
			this->returnButton = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->customerInfoBox = (gcnew System::Windows::Forms::RichTextBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// rentalItemsListBox
			// 
			this->rentalItemsListBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->rentalItemsListBox->FormattingEnabled = true;
			this->rentalItemsListBox->Location = System::Drawing::Point(9, 33);
			this->rentalItemsListBox->Name = L"rentalItemsListBox";
			this->rentalItemsListBox->Size = System::Drawing::Size(220, 173);
			this->rentalItemsListBox->TabIndex = 0;
			this->rentalItemsListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &VideoRentalStoreForm::rentalItemsListBox_SelectedIndexChanged);
			// 
			// rentalItemDescriptionBox
			// 
			this->rentalItemDescriptionBox->Location = System::Drawing::Point(254, 33);
			this->rentalItemDescriptionBox->Name = L"rentalItemDescriptionBox";
			this->rentalItemDescriptionBox->ReadOnly = true;
			this->rentalItemDescriptionBox->Size = System::Drawing::Size(261, 51);
			this->rentalItemDescriptionBox->TabIndex = 1;
			this->rentalItemDescriptionBox->Text = L"";
			this->rentalItemDescriptionBox->WordWrap = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Available Movies";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(251, 17);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Movie Info";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 209);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Rented Movies";
			// 
			// rentedMoviesListBox
			// 
			this->rentedMoviesListBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->rentedMoviesListBox->FormattingEnabled = true;
			this->rentedMoviesListBox->Location = System::Drawing::Point(9, 232);
			this->rentedMoviesListBox->Name = L"rentedMoviesListBox";
			this->rentedMoviesListBox->Size = System::Drawing::Size(220, 173);
			this->rentedMoviesListBox->TabIndex = 5;
			this->rentedMoviesListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &VideoRentalStoreForm::rentedMoviesListBox_SelectedIndexChanged);
			// 
			// rentButton
			// 
			this->rentButton->Location = System::Drawing::Point(254, 109);
			this->rentButton->Name = L"rentButton";
			this->rentButton->Size = System::Drawing::Size(261, 97);
			this->rentButton->TabIndex = 6;
			this->rentButton->Text = L"Rent";
			this->rentButton->UseVisualStyleBackColor = true;
			this->rentButton->Click += gcnew System::EventHandler(this, &VideoRentalStoreForm::rentButton_Click);
			// 
			// returnButton
			// 
			this->returnButton->Location = System::Drawing::Point(254, 308);
			this->returnButton->Name = L"returnButton";
			this->returnButton->Size = System::Drawing::Size(261, 97);
			this->returnButton->TabIndex = 7;
			this->returnButton->Text = L"Return";
			this->returnButton->UseVisualStyleBackColor = true;
			this->returnButton->Click += gcnew System::EventHandler(this, &VideoRentalStoreForm::returnButton_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(535, 451);
			this->tabControl1->TabIndex = 8;
			this->tabControl1->Selected += gcnew System::Windows::Forms::TabControlEventHandler(this, &VideoRentalStoreForm::tabControl1_Selected);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->returnButton);
			this->tabPage1->Controls->Add(this->rentalItemsListBox);
			this->tabPage1->Controls->Add(this->rentedMoviesListBox);
			this->tabPage1->Controls->Add(this->rentButton);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->rentalItemDescriptionBox);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(527, 425);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Movies";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->button1);
			this->tabPage2->Controls->Add(this->customerInfoBox);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(527, 425);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Customer";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(133, 164);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(261, 97);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Cancel Membership";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &VideoRentalStoreForm::button1_Click);
			// 
			// customerInfoBox
			// 
			this->customerInfoBox->Location = System::Drawing::Point(8, 6);
			this->customerInfoBox->Name = L"customerInfoBox";
			this->customerInfoBox->ReadOnly = true;
			this->customerInfoBox->Size = System::Drawing::Size(511, 108);
			this->customerInfoBox->TabIndex = 2;
			this->customerInfoBox->Text = L"";
			this->customerInfoBox->WordWrap = false;
			// 
			// VideoRentalStoreForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(535, 451);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"VideoRentalStoreForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"VideoRentalStoreForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void updateRentalItemsListBox()
	{
		store->updateVideos();
		rentalItemsListBox->Items->Clear();
		RentalItem *rentalItems = store->getRentalItems();

		for (int i = 0; i < store->getNumRentalItems(); i++)
			rentalItemsListBox->Items->Add(gcnew String((rentalItems[i].getTitle().c_str())));
	}
	private: void updateRentedMoviesListBox()
	{
		store->updateCustomers();
		rentedMoviesListBox->Items->Clear();
		Customer *customer = store->getCustomerByPhone(customerPhoneNumber);

		if (customer)
		{
			for (int i = 0; i < customer->getNumMoviesBorrowed(); i++)
				rentedMoviesListBox->Items->Add(gcnew String(store->getRentalItemByID(customer->getMoviesBorrowed()[i])->getTitle().c_str()));
		}
	}
	private: void updateCustomerInfoBox()
	{
		Customer *customer = store->getCustomerByPhone(customerPhoneNumber);

		customerInfoBox->Clear();
		string customerInfo = "Name: " + customer->getName() + "\nPhone Number: " + customer->getPhone() + "\nNumber of movies borrowed: ";
		String^ info = gcnew String(customerInfo.c_str()) + customer->getNumMoviesBorrowed();

		customerInfoBox->AppendText(info);
	}
	private: System::Void rentalItemsListBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (rentalItemsListBox->SelectedIndex < 0)
		{
			rentalItemDescriptionBox->Clear();
			return;
		}

		int i = rentalItemsListBox->SelectedIndex;
		RentalItem rentalItem = store->getRentalItems()[i];
		string desc = "Title: " + rentalItem.getTitle() + "\nGenre: " + rentalItem.getTypeString() + "\nQuantity: ";
		String^ description = gcnew String(desc.c_str()) + rentalItem.getQuantity();

		rentalItemDescriptionBox->Clear();
		rentalItemDescriptionBox->AppendText(description);
	}
	private: System::Void rentedMoviesListBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void rentButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (rentalItemsListBox->SelectedIndex < 0)
	{
		MessageBox::Show("Choose a movie to borrow");
		return;
	}

	int i = rentalItemsListBox->SelectedIndex;
	RentalItem rentalItem = store->getRentalItems()[i];
	
	if (rentalItem.getQuantity() > 0)
	{
		int movieID = rentalItem.getID();
		Customer *customer = store->getCustomerByPhone(customerPhoneNumber);

		if (customer)
		{
			vector<int>::iterator it = find(customer->getMoviesBorrowed().begin(), customer->getMoviesBorrowed().end(), movieID);

			if (it != customer->getMoviesBorrowed().end())
				MessageBox::Show("You have already rented this video", "Video exists");

			else
			{
				store->rentVideo(*customer, movieID);
				store->getRentalItemByID(movieID)->setQuantity(rentalItem.getQuantity() - 1);
				MessageBox::Show("Rented", "Success");
			}
		}
	}

	else
		MessageBox::Show("Out of stock", "Sorry for inconvenience");

	updateRentalItemsListBox();
	rentalItemsListBox->SetSelected(i, true);
	updateRentedMoviesListBox();
}
private: System::Void returnButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (rentedMoviesListBox->SelectedIndex < 0)
	{
		MessageBox::Show("Choose a movie to return");
		return;
	}

	int i = rentedMoviesListBox->SelectedIndex;
	Customer *customer = store->getCustomerByPhone(customerPhoneNumber);
	vector<int> moviesBorrowed = customer->getMoviesBorrowed();
	int movieID = moviesBorrowed[i];

	store->returnVideo(*store->getCustomerByPhone(customerPhoneNumber), movieID);
	store->getRentalItemByID(movieID)->setQuantity(store->getRentalItemByID(movieID)->getQuantity() + 1);

	MessageBox::Show("Returned", "Success");

	int index = rentalItemsListBox->SelectedIndex;
	updateRentalItemsListBox();
	
	if(index >= 0)
		rentalItemsListBox->SetSelected(index, true);

	updateRentedMoviesListBox();
}
private: System::Void tabControl1_Selected(System::Object^  sender, System::Windows::Forms::TabControlEventArgs^  e) {
	updateCustomerInfoBox();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (MessageBox::Show("Cancel membership?", "Are you sure?", MessageBoxButtons::YesNo) == ::DialogResult::Yes)
	{
		Customer *customer = store->getCustomerByPhone(customerPhoneNumber);

		if (customer->getNumMoviesBorrowed() > 0)
		{
			MessageBox::Show("Please return all your movies!", "Cancel Membership");
			return;
		}

		store->removeCustomer(customerPhoneNumber);
		MessageBox::Show("Done!", "Cancelled Membership");
		Close();
	}
}
};
}
