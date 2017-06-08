#pragma once

#include <string>

class Offer {
    std::string title;
    std::string description;
    std::string keywords;

    double price;

public:
    Offer(const std::string& title, const std::string& description, const std::string& keywords, double price);

    const std::string& getTitle() const;
    void setTitle(const std::string& t);

    const std::string& getDescription() const;
    void setDescription(const std::string& d);

    const std::string& getKeywords() const;
    void setKeywords(const std::string& k);

    double getPrice() const;
    void setPrice(double p);

    static Offer createOfferFromText(std::vector<std::string>& lines);

    friend std::ostream& operator<<(std::ostream& os, const Offer& offer);

    void print(std::ostream& os) const;

};
