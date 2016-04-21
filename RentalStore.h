#ifndef RENTALSTORE_H
#define RENTALSTORE_H
#include <vector>

#include "Customer.h"
#include "RentalItem.h"
#include "Database.h"

using namespace std;

class RentalStore
{
public:
	RentalStore(string hostName, string userName, string password);
	~RentalStore();
	void updateCustomers();
	void addCustomer(string firstName, string lastName, string phone);
	bool findCustomer(string phone) const;
	void removeCustomer(string phone);
	RentalItem *getRentalItems();
	RentalItem *getRentalItemByID(int movieID);
	Customer *getCustomers();
	Customer *getCustomerByPhone(string phone);
	int getNumRentalItems() const;
	int getNumCustomers() const;
	virtual void rentVideo(Customer &customer, int movieID) = 0;
	virtual void returnVideo(Customer & customer, int movieID) = 0;
	virtual void updateVideos() = 0;

protected:
	vector<Customer> customers;
	vector<RentalItem> rentalItems;
	Database *db;
};

#endif