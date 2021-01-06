// Copyright (c) 2021 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include "stringcalc.h"

using namespace StringCalc;

bool StringCalc::isZero(std::string string) {

	if (string.empty()) {
		std::cout << "Error: Strings may not be empty!";
		return false;
	}

	for (uint64 i = 0; i < string.length(); i++) {
		if (string[i] != '0') {
			return false;
		}
	}

	return true;
}

std::string StringCalc::removeLeadingZeros(std::string str) {

	if (str.empty()) {
		return "0";
	}

	uint64 counter = 0;
	for (uint64 i = 0; i < str.length() - 1; i++) {
		if (str[i] == '0') {
			counter++;
		}
		else {
			break;
		}
	}

	str.erase(0, counter);
	return str;
}
