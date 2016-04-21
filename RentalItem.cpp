#include "RentalItem.h"

RentalItem::RentalItem(string title, int quantity, int id, int type)
{
	this->title = title;
	this->quantity = quantity;
	this->id = id;
	this->type = type;
}

string RentalItem::getTitle() const
{
	return title;
}

void RentalItem::setTitle(string title)
{
	this->title = title;;
}

int RentalItem::getQuantity() const
{
	return quantity;
}

void RentalItem::setQuantity(int quantity)
{
	this->quantity = quantity;
}

int RentalItem::getID() const
{
	return id;
}

int RentalItem::getType() const
{
	return type;
}

string RentalItem::getTypeString() const
{
	switch (type)
	{
	case 1:
		return "Feature";
	case 2:
		return "Comedy";
	case 3:
		return "Horror";
	default:
		return "Unknown";
	}
}

void RentalItem::setType(int type)
{
	this->type = type;
}