#include "stdafx.h"
#include "Review.h"

std::ostream &operator<<(std::ostream &os, const Review &review) {
	os << "\n" << review.nick << "\n" << review.content << "\n" << review.rating << "\n#\n";
	return os;
}

Review::Review(const std::string &offer, const std::string &nick, const std::string &content, int rating) : offer(
	offer), nick(nick), content(content), rating(rating) {}

const std::string &Review::getOffer() const {
	return offer;
}
