// Copyright (c) 2021 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include "stringcalc.h"

using namespace StringCalc;

Converter::Converter() {
	value = "";
}

Converter::~Converter() {

}

void Converter::parse(std::string str, unsigned int base) {

	// Input sanitization
	if (base < 2 || base > 36) {
		std::cout << "Error: Only the bases from 2 to 36 are allowed!";
		return;
	}
	else if (str.empty()) {
		std::cout << "Error: Number can't be empty!";
		return;
	}

	std::string number = "0";

	// Calculate decimal
	for (uint64 i = 0; i < str.length(); i++) {
		std::string index = std::to_string(str.length() - i - 1);
		std::string coefficient = std::to_string(charToInt(str[i]));
		std::string temp = Decimal::mult(coefficient, Decimal::pow(std::to_string(base), index));
		number = Decimal::add(number, temp);
	}

	// Add number to converter
	value = number;
}

std::string Converter::convertTo(unsigned int base) {

	// Input sanitization
	if (base < 2 || base > 36) {
		std::cout << "Error: Only the bases from 2 to 36 are allowed!";
		return "";
	}
	else if (base == 10) {
		return value;
	}

	std::string result = "";
	std::string decimal = "0";

	// Decimal to base
	for (int i = 0; decimal != "0"; i++) {
		std::string quotient = Decimal::div(decimal, std::to_string(base));
		std::string remainder = Decimal::sub(decimal, Decimal::mult(std::to_string(base), quotient));
		decimal = quotient;

		// 0 to 9
		if (remainder.length() == 1) {
			result.insert(0, remainder);
		}
		else {
			// A to Z
			remainder = StringCalc::intToString(std::atoi(remainder.c_str()));
			result.insert(0, remainder);
		}
	}

	return result;
}
