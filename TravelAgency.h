#pragma once

#include <vector>
#include "Offer.h"

class TravelAgency {
    std::vector<Offer> offers;

    std::vector<std::string> readFile(const std::string& filePath);
    std::vector<Offer> processFileLines(std::vector<std::string>& lines);
    void readAllOffers();
    void printAllOffers() const;

    void displayOffersByKeywords();


public:
    TravelAgency();
    void menu();
};

