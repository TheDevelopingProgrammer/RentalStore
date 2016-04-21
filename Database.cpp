#include "Database.h"

Database::Database(string hostName, string userName, string password)
{
	try
	{
		driver = get_driver_instance();
		connection = unique_ptr<sql::Connection>(driver->connect(hostName, userName, password));
		statement = unique_ptr<sql::Statement>(connection->createStatement());

		connection->setSchema("videorentalstore");

		statement->execute("SET SQL_SAFE_UPDATES = 0;");
	}
	catch (sql::SQLException &e)
	{
		MessageBox::Show(gcnew String(e.what()));
	}
}

void Database::addCustomer(int customerID, string firstName, string lastName, string phone)
{
	try
	{
		stringstream query;
		query << "INSERT INTO customer VALUES(" << customerID << ", '" << firstName << "', '" << lastName << "', '" << phone << "', 0);";
		statement->execute(query.str());
	}
	catch (sql::SQLException &e)
	{
		MessageBox::Show(gcnew String(e.what()));
	}
}

void Database::removeCustomer(string phone)
{
	try
	{
		stringstream query;
		query << "DELETE FROM customer WHERE Phone = '" << phone << "';";
		statement->execute(query.str());
	}
	catch (sql::SQLException &e)
	{
		MessageBox::Show(gcnew String(e.what()));
	}
}

void Database::updateRentedVideos(vector<Customer> &customers)
{
	try
	{
		unique_ptr<sql::ResultSet> res(statement->executeQuery("select * from rented_movies;"));

		while (res->next())
		{
			int customerID = res->getInt("Customer_ID");
			int movieID = res->getInt("Movie_ID");

			for (int i = 0; i < customers.size(); i++)
			{
				if (customers[i].getID() == customerID)
				{
					customers[i].getMoviesBorrowed().push_back(movieID);
					break;
				}
			}
		}
	}
	catch (sql::SQLException &e)
	{
		MessageBox::Show(gcnew String(e.what()));
	}
}

void Database::updateCustomers(vector<Customer> &customers)
{
	customers.clear();

	try
	{
		unique_ptr<sql::ResultSet> res(statement->executeQuery("select * from customer;"));

		while (res->next())
		{
			int customerID = res->getInt("Customer_ID");
			string name = res->getString("First_Name") + " " + res->getString("Last_Name");
			string phone = res->getString("Phone");
			int numMoviesBorrowed = res->getInt("Borrowed_Quantity");

			customers.push_back(Customer(customerID, name, phone, numMoviesBorrowed));
		}
	}
	catch (sql::SQLException &e)
	{
		MessageBox::Show(gcnew String(e.what()));
	}
}

void Database::updateVideos(vector<RentalItem> &rentalItems)
{
	rentalItems.clear();

	try
	{
		unique_ptr<sql::ResultSet> res(statement->executeQuery("select * from movie;"));

		while (res->next())
		{
			int id = res->getInt("Movie_ID");
			string title = res->getString("Title");
			int quantity = res->getInt("Quantity");
			string genre = res->getString("Genre");
			int type;

			if (genre.compare("Feature") == 0)
				type = 1;

			else if (genre.compare("Comedy") == 0)
				type = 2;

			else if (genre.compare("Horror") == 0)
				type = 3;

			rentalItems.push_back(RentalItem(title, quantity, id, type));
		}
	}
	catch (sql::SQLException &e)
	{
		MessageBox::Show(gcnew String(e.what()));
	}
}

void Database::updateVideoQuantity(int movieID, int value)
{
	try
	{
		stringstream query;
		query << "UPDATE movie SET Quantity = Quantity " << (value > 0 ? "+" : "-") << " 1 WHERE Movie_Id = " << movieID << ";";
		statement->execute(query.str());
	}
	catch (sql::SQLException &e)
	{
		MessageBox::Show(gcnew String(e.what()));
	}
}

void Database::updateQuantity(int customerID, int value)
{
	try
	{
		stringstream query;
		query << "UPDATE customer SET Borrowed_Quantity = Borrowed_Quantity " << (value > 0 ? "+" : "-") << " 1 WHERE Customer_ID = " << customerID << ";";
		statement->execute(query.str());
	}
	catch (sql::SQLException &e)
	{
		MessageBox::Show(gcnew String(e.what()));
	}
}

void Database::rentVideo(int customerID, int movieID)
{
	try
	{
		stringstream query;
		query << "INSERT INTO rented_movies VALUES(" << customerID << ", " << movieID << ");";
		statement->execute(query.str());
	}
	catch (sql::SQLException &e)
	{
		MessageBox::Show(gcnew String(e.what()));
	}
}

void Database::returnVideo(int customerID, int movieID)
{
	try
	{
		stringstream query;
		query << "DELETE FROM rented_movies WHERE Customer_ID = " << customerID << " AND Movie_ID = " << movieID << ";";
		statement->execute(query.str());
	}
	catch (sql::SQLException &e)
	{
		MessageBox::Show(gcnew String(e.what()));
	}
}