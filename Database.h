#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <sstream>

#include <cppconn\driver.h>
#include <cppconn\exception.h>
#include <cppconn\resultset.h>
#include <cppconn\statement.h>

#include "Customer.h"
#include "RentalItem.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

class Database
{
public:
	Database(string hostName, string userName, string password);
	void addCustomer(int customerID, string firstName, string lastName, string phone);
	void removeCustomer(string phone);
	void updateRentedVideos(vector<Customer> &customers);
	void updateCustomers(vector<Customer> &customers);
	void updateVideos(vector<RentalItem> &rentalItems);
	void updateVideoQuantity(int movieID, int value);
	void updateQuantity(int customerID, int value);
	void rentVideo(int customerID, int movieID);
	void returnVideo(int customerID, int movieID);

private:
	sql::Driver *driver;
	unique_ptr<sql::Connection> connection;
	unique_ptr<sql::Statement> statement;
};

#endif