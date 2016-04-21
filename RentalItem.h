#ifndef RENTALITEM_H
#define RENTALITEM_H
#include <string>

using namespace std;

class RentalItem
{
public:
	RentalItem(string title, int quantity, int id, int type);
	string getTitle() const;
	void setTitle(string title);
	int getQuantity() const;
	void setQuantity(int quantity);
	int getID() const;
	int getType() const;
	string getTypeString() const;
	void setType(int type);

private:
	string title;
	int quantity;
	int id;
	int type;
};

#endif