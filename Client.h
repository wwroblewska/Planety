#pragma once

#include <string>
#include <iostream>
struct Client {
	std::string name;
	std::string surname;
	std::string city;
	std::string street;
	std::string houseNumber;

	Client();
	Client(const std::string &name, const std::string &surname, const std::string &city, const std::string &street,
		const std::string &houseNumber);


	friend std::ostream& operator<<(std::ostream& os, const Client& client);
	friend std::istream& operator >> (std::istream& is, Client& client);
};
