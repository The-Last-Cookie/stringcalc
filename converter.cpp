// Copyright (c) 2021 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include "stringcalc.h"

using namespace StringCalc;

Converter::Converter() {
	currentBase = 0;
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

	// Add number to converter
	currentBase = base;
	value = str;
}

std::string Converter::convertTo(unsigned int base) {

	// Input sanitization
	if (base < 2 || base > 36) {
		std::cout << "Error: Only the bases from 2 to 36 are allowed!";
		return "";
	}
	else if (base == currentBase) {
		return value;
	}

	std::string result = "";
	std::string decimal = "0";

	// Calculate decimal
	for (uint64 i = 0; i < value.length(); i++) {
		std::string index = std::to_string(value.length() - i - 1);
		std::string coefficient = std::to_string(charToInt(value[i]));
		std::string temp = Decimal::mult(coefficient, Decimal::pow(std::to_string(currentBase), index));
		decimal = Decimal::add(decimal, temp);
	}

	// Decimal to base
	for (int i = 0; decimal != "0"; i++) {
		std::string remainder = Decimal::mod(decimal, std::to_string(base));
		decimal = Decimal::div(decimal, std::to_string(base));
		
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