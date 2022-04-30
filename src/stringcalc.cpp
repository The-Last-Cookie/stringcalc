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
		uint64 zerosToAdd = addend2.length() - addend1.length();
		x.addZeros(zerosToAdd);
	}

	std::string sum = StringCalc::Helper::h_add(base, x.value, y.value);
	return sum;
}

std::string StringCalc::sub(unsigned int base, std::string minuend, std::string subtrahend) {
	Number x(base, minuend);
	Number y(base, subtrahend);

	if (!x.isValid() || !y.isValid()) {
		return "";
	}

	// Add zeros, so both strings have the same length
	if (minuend.length() > subtrahend.length()) {
		uint64 zerosToAdd = minuend.length() - subtrahend.length();
		y.addZeros(zerosToAdd);
	}
	else if (minuend.length() < subtrahend.length()) {
		uint64 zerosToAdd = subtrahend.length() - minuend.length();
		x.addZeros(zerosToAdd);
	}

	// TODO: implement negativity
	if (subtrahend == StringCalc::Helper::max(minuend, subtrahend)) {
		std::cout << "Error: Result may only be positive!\n";
		return "";
	}

	std::string difference = StringCalc::Helper::h_sub(base, x.value, y.value);
	return difference;
}

std::string StringCalc::mult(unsigned int base, std::string factor1, std::string factor2) {
	Number x(base, factor1);
	Number y(base, factor2);

	if (!x.isValid() || !y.isValid()) {
		return "";
	}

	std::string product = StringCalc::Helper::h_mult(base, x.value, y.value);
	return product;
}

std::string StringCalc::div(unsigned int base, std::string dividend, std::string divisor) {
	Number x(base, dividend);
	Number y(base, divisor);

	if (!x.isValid() || !y.isValid()) {
		return "";
	}

	// Divisor needs to be checked first, in case divisor and dividend are both zero
	if (y.isZero()) {
		std::cout << "Error: Division by 0 not allowed!\n";
		return "";
	}
	else if (StringCalc::Helper::max(x.value, y.value) == y.value) {
		return "0";
	}

	std::string quotient = StringCalc::Helper::h_div(base, x.value, y.value, false);
	return quotient;
}

std::string StringCalc::mod(unsigned int base, std::string dividend, std::string divisor) {
	Number x(base, dividend);
	Number y(base, divisor);

	if (!x.isValid() || !y.isValid()) {
		return "";
	}

	if (y.isZero()) {
		std::cout << "Error: Modular arithmetic with 0 not allowed!\n";
		return "";
	}

	std::string remainder = StringCalc::Helper::h_mod(base, x.value, y.value);
	return remainder;
}

std::string StringCalc::pow(unsigned int base, std::string baseExp, std::string exponent) {
	Number x(base, baseExp);
	Number y(base, exponent);

	if (!x.isValid() || !y.isValid()) {
		return "";
	}

	else if (x.isZero() && y.isZero()) {
		std::cout << "Error: 0 ^ 0 is not defined!\n";
		return "";
	}

	std::string power = StringCalc::Helper::h_pow(base, x.value, y.value);
	return power;
}

std::string StringCalc::fact(unsigned int base, std::string num) {
	Number x(base, num);

	if (!x.isValid()) {
		return "";
	}

	std::string factorial = StringCalc::Helper::h_fact(base, x.value);
	return factorial;
}
