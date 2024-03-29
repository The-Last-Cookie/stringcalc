// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include <string>

#include "stringcalc.h"

using namespace StringCalc;

Converter::Converter() {
	// Always in base 10
	value = "";
}

Converter::~Converter() {

}

void Converter::parse(std::string str, unsigned int base) {
	Number num = Number(base, str);

	if (!num.isValid()) {
		return;
	}

	std::string number = "0";

	// Calculate decimal value
	// Take the highest exponent first
	for (uint64 i = 0; i < str.length(); i++) {
		std::string index = std::to_string(str.length() - i - 1);
		std::string coefficient = std::to_string(StringCalc::Helper::charToInt(str[i]));
		std::string temp = StringCalc::mult(
			10,
			coefficient,
			StringCalc::pow(10, std::to_string(base), index));
		number = StringCalc::add(10, number, temp);
	}

	value = number;
}

std::string Converter::convertTo(unsigned int base) {

	// Input sanitization
	if (base < 2 || base > 36) {
		std::cout << "Error: Only the bases from 2 to 36 are allowed!\n";
		return "";
	}
	else if (value == "") {
		std::cout << "Error: Nothing got parsed into the converter.\n";
		return "";
	}
	else if (base == 10) {
		return value;
	}
	else if (value == "0") {
		return value;
	}

	std::string result = "";
	std::string quotient = value;

	// Decimal to base
	while (quotient != "0") {
		std::string temp = quotient;
		quotient = StringCalc::div(10, quotient, std::to_string(base));
		std::string remainder = StringCalc::mod(10, temp, std::to_string(base));

		// Convert numbers over 9 to letters
		remainder = StringCalc::Helper::intToString(std::atoi(remainder.c_str()));
		result += remainder;
	}

	reverse(result.begin(), result.end());
	return result;
}
