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

void Converter::parse(std::string num, unsigned int base) {

	// Input sanitization
	if (base < 2 || base > 36) {
		std::cout << "Error: Only the bases from 2 to 36 are allowed!";
		return;
	}
	else if (num.empty()) {
		std::cout << "Error: Number can't be empty!";
		return;
	}

	// Add number to converter
	currentBase = base;
	value = num;
}

std::string Converter::convertTo(int base) {
	return "";
}
