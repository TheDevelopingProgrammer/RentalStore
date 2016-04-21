#include "RentalStore.h"

RentalStore::RentalStore(string hostName, string userName, string password)
{
	db = new Database(hostName, userName, password);
	updateCustomers();
}

RentalStore::~RentalStore()
{
	delete db;
}

void RentalStore::updateCustomers()
{
	db->updateCustomers(customers);
	db->updateRentedVideos(customers);
}

void RentalStore::addCustomer(string firstName, string lastName, string phone)
{
	int uniqueID = 1;

	for (int i = 0; i < customers.size(); i++)
	{
		if (customers[i].getID() == uniqueID)
			uniqueID++;
	}

	db->addCustomer(uniqueID, firstName, lastName, phone);
	updateCustomers();
}

bool RentalStore::findCustomer(string phone) const
{
	for (int i = 0; i < customers.size(); i++)
	{
		if (customers[i].getPhone() == phone)
			return true;
	}

	return false;
}

void RentalStore::removeCustomer(string phone)
{
	db->removeCustomer(phone);
	updateCustomers();
}

RentalItem *RentalStore::getRentalItems()
{
	return rentalItems.data();
}

RentalItem *RentalStore::getRentalItemByID(int movieID)
{
	for (int i = 0; i < rentalItems.size(); i++)
	{
		if (rentalItems[i].getID() == movieID)
			return &rentalItems[i];
	}

	return nullptr;
}

Customer *RentalStore::getCustomers()
{
	return customers.data();
}

Customer *RentalStore::getCustomerByPhone(string phone)
{
	for (int i = 0; i < customers.size(); i++)
	{
		if (customers[i].getPhone() == phone)
			return &customers[i];
	}

	return nullptr;
}

int RentalStore::getNumRentalItems() const
{
	return rentalItems.size();
}

int RentalStore::getNumCustomers() const
{
	return customers.size();
}