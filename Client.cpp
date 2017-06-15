
#include "Client.h"

Client::Client(const std::string &name, const std::string &surname, const std::string &city, const std::string &street, const std::string &houseNumber)
	: name(name), surname(surname), city(city), street(street), houseNumber(houseNumber) {

}

Client::Client() {

}

std::ostream &operator<<(std::ostream &os, const Client &client) {
	os << client.name << " " << client.surname << " " << client.city << " " << client.street << " " << client.houseNumber;
	return os;
}

std::istream &operator >> (std::istream &is, Client &client) {
	is >> client.name >> client.surname >> client.city >> client.street >> client.houseNumber;
	return is;
}



