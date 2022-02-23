// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include "number.h"

StringCalc::Number::Number(unsigned int base, std::string value) {
	this->base = 0;
	m_isValid = false;

	// Has to be set here because the parameter will be accessed for checks
	this->value = value;

	if (!isInBase(base)) {
		this->value = "";
		return;
	}

	this->base = base;

	m_isValid = true;
}

StringCalc::Number::~Number() {
}

bool StringCalc::Number::isZero() {
	for (uint64 i = 0; i < this->value.length(); i++) {
		if (this->value[i] != '0') {
			return false;
		}
	}

	return true;
}

void StringCalc::Number::addZeros(uint64 count) {
	this->value.insert(0, count, '0');
}

bool StringCalc::Number::isValid() {
	return m_isValid;
}

bool StringCalc::Number::isInBase(unsigned int base) {
	if (this->value.empty()) {
		std::cout << "Error: Strings may not be empty!";
		return false;
	}
	else if (base < 2 || base > 36) {
		std::cout << "Error: Only the bases from 2 to 36 are allowed!";
		return false;
	}

	for (uint64 i = 0; i < this->value.length(); i++) {
		int c = Helper::charToInt(this->value[i]);
		if (c == -1 || c >= base) {
			return false;
		}
	}

	return true;
}
