#pragma once

#include <vector>
#include "Offer.h"
#include "Client.h"

class TravelAgency {
	std::vector<Offer> offers;

	std::vector<std::string> readFile(const std::string& filePath);
	std::vector<Offer> processFileLines(std::vector<std::string>& lines);
	void readAllOffers();
	void printAllOffers() const;

	void displayOffersByKeywords();
	void displayOffersInPriceRange() const;
	void selectOfferDialog();


	bool checkIfOfferExsists(const std::string& name);
	void makeOrder(const std::string& offer, const Client& client);

public:
	TravelAgency();
	void menu();

	void addReviewDialog();

	void showReviewDialog();
};

