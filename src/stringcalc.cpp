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
	if (x.value.length() > y.value.length()) {
		uint64 zerosToAdd = x.value.length() - y.value.length();
		y.addZeros(zerosToAdd);
	}
	else if (x.value.length() < y.value.length()) {
		uint64 zerosToAdd = y.value.length() - x.value.length();
		x.addZeros(zerosToAdd);
	}

	// Number x gets reused for result to save memory space
	if (!x.isNegative() && y.isNegative()) {
		if (StringCalc::Helper::max(x.value, y.value) == x.value) {
			// Result is positive
			x.value = StringCalc::Helper::h_sub(base, x.value, y.value);
		}
		else if (x.value == y.value) {
			return "0";
		}
		else {
			// Result is negative
			x.value = StringCalc::Helper::h_sub(base, y.value, x.value);
			x.setNegative();
		}
	}
	else if (x.isNegative() && !y.isNegative()) {
		if (StringCalc::Helper::max(x.value, y.value) == y.value) {
			// Result is positive
			x.value = StringCalc::Helper::h_sub(base, y.value, x.value);

			// x is reused and thus needs to be set explicitely to being positive
			x.setPositive();
		}
		else if (x.value == y.value) {
			return "0";
		}
		else {
			// Result is negative
			x.value = StringCalc::Helper::h_sub(base, x.value, y.value);
			x.setNegative();
		}
	}
	else if (x.isNegative() && y.isNegative()) {
		x.value = StringCalc::Helper::h_add(base, x.value, y.value);
		x.setNegative();
	}
	else {
		// Both numbers are positive
		x.value = StringCalc::Helper::h_add(base, x.value, y.value);
	}

	return x.toString();
}

std::string StringCalc::sub(unsigned int base, std::string minuend, std::string subtrahend) {
	Number x(base, minuend);
	Number y(base, subtrahend);

	if (!x.isValid() || !y.isValid()) {
		return "";
	}

	// Add zeros, so both strings have the same length
	if (x.value.length() > y.value.length()) {
		uint64 zerosToAdd = x.value.length() - y.value.length();
		y.addZeros(zerosToAdd);
	}
	else if (x.value.length() < y.value.length()) {
		uint64 zerosToAdd = y.value.length() - x.value.length();
		x.addZeros(zerosToAdd);
	}

	// Number x gets reused for result to save memory space
	if (!x.isNegative() && y.isNegative()) {
		if (StringCalc::Helper::max(x.value, y.value) == x.value) {
			// Result is positive
			x.value = StringCalc::Helper::h_add(base, x.value, y.value);
		}
		else {
			x.value = StringCalc::Helper::h_add(base, y.value, x.value);
			x.setPositive();
		}
	}
	else if (x.isNegative() && !y.isNegative()) {
		if (StringCalc::Helper::max(x.value, y.value) == y.value) {
			// Result is positive
			x.value = StringCalc::Helper::h_add(base, y.value, x.value);
		}
		else {
			// Result is negative
			x.value = StringCalc::Helper::h_add(base, x.value, y.value);
		}
	}
	else if (x.isNegative() && y.isNegative()) {
		if (StringCalc::Helper::max(x.value, y.value) == x.value) {
			x.value = StringCalc::Helper::h_sub(base, x.value, y.value);
		}
		else {
			x.value = StringCalc::Helper::h_sub(base, y.value, x.value);
			x.setPositive();
		}
	}
	else {
		// Both numbers are positive
		if (StringCalc::Helper::max(x.value, y.value) == x.value) {
			x.value = StringCalc::Helper::h_sub(base, x.value, y.value);
		}
		else {
			x.value = StringCalc::Helper::h_sub(base, y.value, x.value);
		}
	}

	return x.toString();
}

std::string StringCalc::mult(unsigned int base, std::string factor1, std::string factor2) {
	Number x(base, factor1);
	Number y(base, factor2);

	if (!x.isValid() || !y.isValid()) {
		return "";
	}

	if (x.isNegative() && y.isNegative()) {
		x.value = StringCalc::Helper::h_mult(base, x.value, y.value);
		x.setPositive();
	}
	else if (x.isNegative() || y.isNegative()) {
		x.value = StringCalc::Helper::h_mult(base, x.value, y.value);

		if (x.value == "0") {
			x.setPositive();
		}
	}
	else {
		x.value = StringCalc::Helper::h_mult(base, x.value, y.value);
	}

	return x.toString();
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

	// Only set negative if one of the numbers is negative
	if (!x.isNegative() != !y.isNegative()) {
		x.value = StringCalc::Helper::h_div(base, x.value, y.value, false);
		x.setNegative();
	}
	else {
		x.value = StringCalc::Helper::h_div(base, x.value, y.value, false);
	}

	return x.toString();
}

std::string StringCalc::mod(unsigned int base, std::string dividend, std::string divisor) {
	Number x(base, dividend);
	Number y(base, divisor);

	if (!x.isValid() || !y.isValid()) {
		return "";
	}

	if (StringCalc::Helper::max("2", y.value) == "2" || y.isNegative()) {
		std::cout << "Error: Modular arithmetic with less than 1 not allowed!\n";
		return "";
	}

	if (x.isNegative()) {
		return StringCalc::Helper::h_mod(base, y.value, x.value);
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
	else if (y.isNegative()) {
		std::cout << "Error: Floating values not supported!\n";
		return "";
	}

	x.value = StringCalc::Helper::h_pow(base, x.value, y.value);

	if (x.isNegative() && (StringCalc::mod(base, y.value, "2") == "1")) {
		return x.toString();
	}

	return x.value;
}

std::string StringCalc::fact(unsigned int base, std::string num) {
	Number x(base, num);

	if (!x.isValid()) {
		return "";
	}
	else if (x.isZero()) {
		return "1";
	}

	std::string factorial = StringCalc::Helper::h_fact(base, x.value);
	return factorial;
}
