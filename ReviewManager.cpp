#include "stdafx.h"
#include "ReviewManager.h"
#include <fstream>

void ReviewManager::saveReview(const Review &review) {
	std::string filePath = review.getOffer() + ".txt";
	std::ofstream out(filePath, std::ios::app);

	out << review << std::endl;

	out.close();
}

std::string ReviewManager::readReviews(const std::string &offer) {
	std::string filePath = offer + ".txt";
	std::ifstream in(filePath);

	if (!in.is_open()) {
		return std::string("Brak recenzji dla tej oferty.\n");
	}


	std::string line, out;
	while (std::getline(in, line)) {
		if (line == "#") {
			out += "\n";
		}
		else {
			out += line + "\n";
		}
	}

	return out;
}
