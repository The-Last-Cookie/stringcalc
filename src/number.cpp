// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include "number.h"
#include "helper.h"

StringCalc::Number::Number(unsigned int base, std::string value) {
	this->m_base = 0;
	this->m_value = value;
	this->isValid = false;

	if (!isInBase(base)) {
		this->m_value = "";
		return;
	}

	this->m_base = base;
	this->isValid = true;
}

StringCalc::Number::~Number() {
}

bool StringCalc::Number::isZero() {
	for (uint64 i = 0; i < m_value.length(); i++) {
		if (m_value[i] != '0') {
			return false;
		}
	}

	return true;
}

void StringCalc::Number::removeLeadingZeros() {
	uint64 counter = 0;
	for (uint64 i = 0; i < m_value.length() - 1; i++) {
		if (m_value[i] == '0') {
			counter++;
		}
		else {
			break;
		}
	}

	m_value.erase(0, counter);
}

bool StringCalc::Number::isInBase(unsigned int base) {
	if (m_value.empty()) {
		std::cout << "Error: Strings may not be empty!";
		return false;
	}
	else if (base < 2 || base > 36) {
		std::cout << "Error: Only the bases from 2 to 36 are allowed!";
		return false;
	}

	for (uint64 i = 0; i < m_value.length(); i++) {
		int c = Helper::charToInt(m_value[i]);
		if (c == -1 || c >= base) {
			return false;
		}
	}

	removeLeadingZeros();
	return true;
}
