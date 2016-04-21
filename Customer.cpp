#include "Customer.h"

Customer::Customer(int id, string name, string phone, int numMoviesBorrowed)
{
	this->id = id;
	this->name = name;
	this->phone = phone;
	this->numMoviesBorrowed = numMoviesBorrowed;
}

string Customer::getName() const
{
	return name;
}

void Customer::setName(string name)
{
	this->name = name;
}

string Customer::getPhone() const
{
	return phone;
}

void Customer::setPhone(string phone)
{
	this->phone = phone;
}

void Customer::rentVideo(int movieID)
{
	movieIds.push_back(movieID);
	numMoviesBorrowed++;
}

void Customer::returnVideo(int movieID)
{
	for (int i = 0; i < movieIds.size(); i++)
	{
		if (movieIds[i] == movieID)
		{
			movieIds.erase(movieIds.begin() + i);
			numMoviesBorrowed--;
		}
	}
}

vector<int> &Customer::getMoviesBorrowed()
{
	return movieIds;
}

int Customer::getNumMoviesBorrowed() const
{
	return numMoviesBorrowed;
}

int Customer::getID() const
{
	return id;
}