#ifndef VIDEOSTORE_H
#define VIDEOSTORE_H
#include "RentalStore.h"

class VideoStore : public RentalStore
{
public:
	VideoStore(string hostName, string userName, string password);
	virtual void rentVideo(Customer &customer, int movieID);
	virtual void returnVideo(Customer &customer, int movieID);
	virtual void updateVideos();
};

#endif