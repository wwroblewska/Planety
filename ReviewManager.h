#pragma once

#include "Review.h"
#include <iostream>

class ReviewManager {
public:
	static void saveReview(const Review& review);
	static std::string readReviews(const std::string& offer);
};

