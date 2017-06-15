#pragma once

#include <string>
#include <ostream>

class Review {
	std::string offer;
	std::string nick;
	std::string content;
	int rating;
public:

	Review(const std::string &offer, const std::string &nick, const std::string &content, int rating);

	friend std::ostream &operator<<(std::ostream &os, const Review &review);

	const std::string &getOffer() const;
};

