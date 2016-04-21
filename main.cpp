#include "DatabaseForm.h"

using namespace System;
using namespace System::Windows::Forms;

string customerPhoneNumber;
RentalStore *store = nullptr;

#define HOSTNAME "127.0.0.1"
#define USERNAME "root"
#define PASSWORD "root"

[STAThread]
void main()
{
	store = new VideoStore(HOSTNAME, USERNAME, PASSWORD);

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew VideoRentalStoreRevised::DatabaseForm);
}