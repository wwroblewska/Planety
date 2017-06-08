#include "Offer.h"
#include <iostream>
#include <cstdlib>
#include <vector>

Offer::Offer(const std::string &title, const std::string &description, const std::string &keywords, double price)
    : title(title), description(description), keywords(keywords), price(price)
{

}

const std::string& Offer::getTitle() const {
    return title;
}

const std::string& Offer::getDescription() const {
    return description;
}

const std::string& Offer::getKeywords() const {
    return keywords;
}

double Offer::getPrice() const {
    return price;
}

void Offer::setDescription(const std::string &d) {
    description = d;
}

void Offer::setKeywords(const std::string &k) {
    keywords = k;
}

void Offer::setTitle(const std::string &t) {
    title = t;
}

void Offer::setPrice(double p) {
    price = p;
}


std::ostream& operator<<(std::ostream& os, const Offer& offer) {
    os << offer.title << "\n" << offer.description  << offer.keywords << "\n" << offer.price;
    return os;
}

Offer Offer::createOfferFromText(std::vector<std::string>& lines) {
    Offer out(" ", " ", " ", 0.0);


    out.setTitle(lines[0]);
    out.setKeywords(lines[lines.size()-2]);
    out.setPrice(atof(lines[lines.size()-1].c_str()));


    std::string combinedDescription;
    for(int i = 1; i < lines.size() - 2; i++) {
        combinedDescription += lines[i] + "\n";
    }

    out.setDescription(combinedDescription);

    //std::cout << "Stworzono oferte: \n" << out << std::endl;

    return out;
}

void Offer::print(std::ostream &os) const {
    std::cout << "\nNazwa oferty:\t" << title << std::endl;
    std::cout << "Cena:\t" << price << std::endl << std::endl;
    std::cout << "Opis: " << std::endl << description << std::endl;
    std::cout << "Slowa kluczowe: " << keywords << std::endl;
}
