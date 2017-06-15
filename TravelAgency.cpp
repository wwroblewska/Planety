#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>

#include "TravelAgency.h"
#include "Client.h"
#include "Review.h"
#include "ReviewManager.h"


void TravelAgency::readAllOffers() {
	std::vector<std::string> lines = readFile("plik.txt");
	offers = processFileLines(lines);
}

std::vector<std::string> TravelAgency::readFile(const std::string &filePath) {
	std::vector<std::string> allLines;

	std::ifstream in(filePath);


	if (!in.is_open()) {
		std::cout << "Nie udalo sie otworzyc pliku z ofetami.\n";
		return  allLines;
	}

	std::string oneLine;

	while (std::getline(in, oneLine)) {
		allLines.push_back(oneLine);
	}
	return allLines;
}

std::vector<Offer> TravelAgency::processFileLines(std::vector<std::string>& lines) {
	std::vector<std::string> oneOfferLines;
	std::vector<Offer> resutl;

	if (lines.size() == 0) {
		std::cout << "Brak ofert do przetworzenia.\n";
		return resutl;
	}

	////
	while (lines.size() > 1) {
		for (int i = 0; i < lines.size(); i++) {
			if (lines[i] != "#") {
				oneOfferLines.push_back(lines[i]);
			}
			else {
				break;
			}
		}

		resutl.push_back(Offer::createOfferFromText(oneOfferLines));


		lines.erase(lines.begin(), lines.begin() + oneOfferLines.size() + 1);
		//std::cout << lines.size() << std::endl;
		//std::cout << lines[0] << std::endl;
		// wyczyszczenie linijek poprzedniej oferty
		oneOfferLines.clear();
	}

	return resutl;
}

void TravelAgency::printAllOffers() const {
	for (int i = 0; i < offers.size(); i++) {
		offers[i].print(std::cout);
	}
}


void TravelAgency::displayOffersInPriceRange() const {
	double low, high;
	std::cout << "Podaj dolny zakres ceny: ";
	std::cin >> low;

	std::cout << "Podaj gorny zakres ceny: ";
	std::cin >> high;


	for (int i = 0; i < offers.size(); i++) {
		if (offers[i].getPrice() >= low && offers[i].getPrice() <= high)
			offers[i].print(std::cout);
	}
}

void TravelAgency::selectOfferDialog() {
	std::string name;
	std::cout << "Podaj nazwe oferty: ";

	std::cin.ignore(1000000, '\n');
	std::getline(std::cin, name);

	if (!checkIfOfferExsists(name)) {
		std::cout << "Nie ma oferty o takiej nazwie.\n";
		return;
	}

	std::cout << "Podaj swoje dane - imie, nazwisko, miasto, ulice, numer budynku: ";
	Client client;
	std::cin >> client;

	makeOrder(name, client);
}

void TravelAgency::menu() {
	int wybor = 0;

	do {
		std::cout << "\n1) Pokaz wszystkie oferty.\n";
		std::cout << "2) Znajdz oferte po slowach kluczowych.\n";
		std::cout << "3) Pokaz oferty w zakresie cenowym.\n";
		std::cout << "4) Wybierz oferte.\n";
		std::cout << "5) Dodaj recenzje.\n";
		std::cout << "6) Zobacz recenzje.\n";
		std::cout << "7) Wyjscie.\n";

		std::cin >> wybor;

		switch (wybor) {
		case 1:
			printAllOffers();
			break;
		case 2:
			displayOffersByKeywords();
			break;
		case 3:
			displayOffersInPriceRange();
			break;
		case 4:
			selectOfferDialog();
			break;
		case 5:
			addReviewDialog();
			break;
		case 6:
			showReviewDialog();
			break;

		}

	} while (wybor != 7);

}

void TravelAgency::displayOffersByKeywords() {
	std::string keywords;
	std::cout << "Podaj slowa kluczowe: ";
	std::cin.ignore(1000000, '\n');

	std::getline(std::cin, keywords);


	std::vector<std::string> singleKeywords;

	std::stringstream ss(keywords);

	std::string tmp;
	while (ss >> tmp) {
		singleKeywords.push_back(tmp);
	}


	for (int i = 0; i < offers.size(); i++) {
		for (int j = 0; j < singleKeywords.size(); j++) {
			if (offers[i].getKeywords().find(singleKeywords[j]) != std::string::npos) {
				offers[i].print(std::cout);
				break;
			}
		}

	}
}

TravelAgency::TravelAgency() {
	readAllOffers();
}

bool TravelAgency::checkIfOfferExsists(const std::string &name) {

	for (int i = 0; i < offers.size(); i++) {
		if (offers[i].getTitle() == name) {
			return true;
		}
	}
	return false;
}

void TravelAgency::makeOrder(const std::string &offer, const Client &client) {
	std::string fileName = client.name + "_" + client.surname;

	time_t currentTimeRaw;
	time(&currentTimeRaw);

	struct tm* currentTime;
	currentTime = localtime(&currentTimeRaw);


	std::string dateString(asctime(currentTime));


	fileName += "_" + dateString + ".txt";


	for (int i = 0; i < offers.size(); i++) {
		if (offers[i].getTitle() == offer) {
			std::ofstream out(fileName);
			out << client << std::endl << "\n\nSzczegoly oferty\n\n" << offers[i] << std::endl;
			out.close();
			return;
		}
	}
}

void TravelAgency::addReviewDialog() {
	std::string offer, nick, content;
	int rating;

	std::cout << "Podaj nazwe oferty: ";
	std::cin.ignore(10000, '\n');
	std::getline(std::cin, offer);

	std::cout << "Podaj nick: ";
	std::cin >> nick;

	std::cout << "Napisz recenzje: ";
	std::cin.ignore(10000, '\n');
	std::getline(std::cin, content);

	std::cout << "Podaj ocene [0 - 5]: ";
	std::cin >> rating;

	Review review(offer, nick, content, rating);
	ReviewManager::saveReview(review);
}

void TravelAgency::showReviewDialog() {
	std::string offer;

	std::cout << "Podaj nazwe ofert: ";
	std::cin.ignore(10000, '\n');
	std::getline(std::cin, offer);

	std::cout << ReviewManager::readReviews(offer) << std::endl;
}
