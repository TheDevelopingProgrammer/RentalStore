#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include <algorithm>

#include "RentalItem.h"

using namespace std;

class Customer
{
public:
	Customer(int id, string name, string phone, int numMoviesBorrowed);
	string getName() const;
	void setName(string name);
	string getPhone() const;
	void setPhone(string phone);
	void rentVideo(int movieID);
	void returnVideo(int movieID);
	vector<int> &getMoviesBorrowed();
	int getNumMoviesBorrowed() const;
	int getID() const;

private:
	string name;
	string phone;
	vector<int> movieIds;
	int numMoviesBorrowed;
	int id;
};

#endif