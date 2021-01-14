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

std::string StringCalc::intToString(int num) {

	// 0 to 9
	if (num >= 0 && num <= 9) {
		return std::to_string(num);
	}
	// A to Z
	else if (num >= 10 && num <= 35) {
		char c = num + 55;
		std::string s;
		s = c;
		return s;
	}

	std::cout << "Error: Couldn't convert int correctly to string.";
	return "";
}

int StringCalc::charToInt(char c) {

	if (c >= '0' && c <= '9') {
		return c - 48;
	}
	else if (c >= 'A' && c <= 'Z') {
		return c - 55;
	}
	else if (c >= 'a' && c <= 'z') {
		return c - 87;
	}

	std::cout << "Error: Couldn't convert char correctly to int.";
	return -1;
}

bool StringCalc::isInBase(std::string str, unsigned int base) {

	// Input sanitization
	if (str.empty()) {
		std::cout << "Error: Strings may not be empty!";
		return false;
	}
	else if (base < 2 || base > 36) {
		std::cout << "Error: Only the bases from 2 to 36 are allowed!";
		return false;
	}

	for (uint64 i = 0; i < str.length(); i++) {
		if (charToInt(str[i]) == -1 ||
			charToInt(str[i]) >= base) {
			return false;
		}
	}

	return true;
}
