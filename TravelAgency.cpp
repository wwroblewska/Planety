#include <fstream>
#include <iostream>
#include <sstream>

#include "TravelAgency.h"


void TravelAgency::readAllOffers() {
    std::vector<std::string> lines = readFile("plik.txt");
    offers = processFileLines(lines);

    //std::cout << "Wczytano " << offers.size() << " ofert.\n";
}

std::vector<std::string> TravelAgency::readFile(const std::string &filePath) {
    std::vector<std::string> allLines;

    std::ifstream in(filePath);


    if(!in.is_open()) {
        std::cout << "Nie udalo sie otworzyc pliku z ofetami.\n";
        return  allLines;
    }

    std::string oneLine;

    while(std::getline(in, oneLine)) {
        allLines.push_back(oneLine);
    }

    //std::cout << "Wczytano " << allLines.size() << std::endl;

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
            } else {
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
    for(int i = 0; i < offers.size(); i++) {
        offers[i].print(std::cout);
    }
}

void TravelAgency::menu() {
    int wybor = 0;

    do {
        std::cout << "\n1) Pokaz wszystkie oferty.\n";
        std::cout << "2) Znajdz oferte po slowach kluczowych.\n";
        std::cout << "3) Pokaz oferty w zakresie cenowym.\n";
        std::cout << "4) Wybierz oferte.\n";
        std::cout << "5) Wyjscie.\n";

        std::cin >> wybor;

        switch (wybor) {
            case 1:
                printAllOffers();
                break;
            case 2:
                displayOffersByKeywords();
                break;
        }

    } while(wybor != 5);

}

void TravelAgency::displayOffersByKeywords() {
    std::string keywords;
    std::cout << "Podaj slowa kluczowe: ";
    std::cin.ignore(1000000, '\n');

    std::getline(std::cin, keywords);


    std::vector<std::string> singleKeywords;

    std::stringstream ss(keywords);

    std::string tmp;
    while(ss >> tmp) {
        singleKeywords.push_back(tmp);
    }


    for(int i = 0; i < offers.size(); i++) {
        for(int j = 0; j < singleKeywords.size(); j++) {
            if(offers[i].getKeywords().find(singleKeywords[j]) != std::string::npos) {
                offers[i].print(std::cout);
                break;
            }
        }

    }
}

TravelAgency::TravelAgency() {
    readAllOffers();
}
