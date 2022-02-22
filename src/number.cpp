// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include "number.h"

StringCalc::Number::Number(unsigned int base, std::string value) {
	base = 0;
	value = "";
	m_isValid = false;

	if (!isInBase(base)) {
		return;
	}

	base = base;
	value = StringCalc::Helper::removeLeadingZeros(value);
	m_isValid = true;
}

StringCalc::Number::~Number() {
}

bool StringCalc::Number::isZero() {
	for (uint64 i = 0; i < value.length(); i++) {
		if (value[i] != '0') {
			return false;
		}
	}

	return true;
}

void StringCalc::Number::addZeros(uint64 count) {
	value.insert(0, count, '0');
}

bool StringCalc::Number::isValid() {
	return m_isValid;
}

bool StringCalc::Number::isInBase(unsigned int base) {
	if (value.empty()) {
		std::cout << "Error: Strings may not be empty!";
		return false;
	}
	else if (base < 2 || base > 36) {
		std::cout << "Error: Only the bases from 2 to 36 are allowed!";
		return false;
	}

	for (uint64 i = 0; i < value.length(); i++) {
		int c = Helper::charToInt(value[i]);
		if (c == -1 || c >= base) {
			return false;
		}
	}

	return true;
}
