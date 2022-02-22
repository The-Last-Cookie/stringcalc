// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include "stringcalc.h"

std::string StringCalc::add(unsigned int base, std::string addend1, std::string addend2) {
	Number x(base, addend1);
	Number y(base, addend2);

	if (!x.isValid() || !y.isValid()) {
		return "";
	}

	// Add zeros, so both strings have the same length
	if (addend1.length() > addend2.length()) {
		uint64 zerosToAdd = addend1.length() - addend2.length();
		y.addZeros(zerosToAdd);
	}
	else if (addend1.length() < addend2.length()) {
		uint64 zerosToAdd = addend2.length() - addend2.length();
		x.addZeros(zerosToAdd);
	}

	std::string sum = StringCalc::Helper::h_add(base, x.getValue(), y.getValue());

	// TODO: improve
	Number n(base, sum);
	n.removeLeadingZeros();
	
	return n.getValue();
}

std::string StringCalc::sub(std::string minuend, std::string subtrahend) {
	return "";
}

std::string StringCalc::mult(std::string factor1, std::string factor2) {
	return "";
}

std::string StringCalc::div(std::string dividend, std::string divisor) {
	return "";
}

std::string StringCalc::mod(std::string dividend, std::string divisor) {
	return "";
}

std::string StringCalc::pow(std::string base, std::string exponent) {
	return "";
}

std::string StringCalc::fact(std::string num) {
	return "";
}
