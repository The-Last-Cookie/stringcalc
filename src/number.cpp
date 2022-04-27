// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include "number.h"

StringCalc::Number::Number(unsigned int base, std::string value) {
	this->base = 0;
	m_isValid = false;
	m_isNegative = false;

	// Has to be set here because the parameter will be accessed for checks
	this->value = value;

	if (!isInBase(base)) {
		this->value = "";
		return;
	}

	if (checkNegative()) {
		setNegative();
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

bool StringCalc::Number::isNegative() {
	return this->m_isNegative;
}

void StringCalc::Number::setNegative() {
	this->m_isNegative = true;

	// Remove minus at the beginning
	this->value.erase(0, 1);
}

std::string StringCalc::Number::toString() {
	if (this->m_isNegative) {
		return "-" + value;
	}

	return value;
}

bool StringCalc::Number::isInBase(unsigned int base) {
	if (this->value.empty()) {
		std::cout << "Error: Strings may not be empty!\n";
		return false;
	}
	else if (base < 2 || base > 36) {
		std::cout << "Error: Only the bases from 2 to 36 are allowed!\n";
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

bool StringCalc::Number::checkNegative()
{
	if (this->value[0] == '-') {
		return true;
	}

	return false;
}
