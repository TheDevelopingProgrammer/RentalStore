#include "VideoStore.h"

VideoStore::VideoStore(string hostName, string userName, string password) : RentalStore(hostName, userName, password)
{
	updateVideos();
}

void VideoStore::rentVideo(Customer &customer, int movieID)
{
	db->rentVideo(customer.getID(), movieID);
	db->updateQuantity(customer.getID(), 1);
	db->updateVideoQuantity(movieID, -1);
	customer.rentVideo(movieID);
}

void VideoStore::returnVideo(Customer & customer, int movieID)
{
	db->returnVideo(customer.getID(), movieID);
	db->updateQuantity(customer.getID(), -1);
	db->updateVideoQuantity(movieID, 1);
	customer.returnVideo(movieID);
}

void VideoStore::updateVideos()
{
	db->updateVideos(rentalItems);
}