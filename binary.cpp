// Copyright (c) 2021 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include "stringcalc.h"

using namespace StringCalc;

std::string Binary::add_b(std::string addend1, std::string addend2) {

	// Input sanitization
	if (!isBinary(addend1) || !isBinary(addend2)) {
		std::cout << "Error: Strings may only contain positive binary numbers!" << "\n";
		return "";
	}

	// Add zeros, so both strings have the same length
	if (addend1.length() > addend2.length()) {
		int64 len = addend1.length() - addend2.length();
		addend2.insert(0, len, '0');
	}
	else if (addend1.length() < addend2.length()) {
		int64 len = addend2.length() - addend1.length();
		addend1.insert(0, len, '0');
	}

	std::string sum = "";

	// Add single digits together
	int carrier = 0;
	for (int64 i = addend1.length() - 1; i >= 0; i--) {
		// ASCII value convertion
		int temp = addend1[i] + addend2[i] + carrier - 96;

		if (temp > 1) {
			carrier = 1;
			temp = temp % 2;
		}
		else {
			carrier = 0;
		}

		sum.insert(0, std::to_string(temp));
	}

	// Insert carrier
	if (carrier == 1) {
		sum.insert(0, std::to_string(carrier));
	}

	sum = removeLeadingZeros(sum);
	return sum;
}

std::string Binary::sub_b(std::string minuend, std::string subtrahend) {

	// Input sanitization
	if (!isBinary(minuend) || !isBinary(subtrahend)) {
		std::cout << "Error: Strings may only contain positive binary numbers!" << "\n";
		return "";
	}

	// Negative difference
	if (subtrahend == max_b(minuend, subtrahend)) {
		std::cout << "Error: Result may only be positive!";
		return "";
	}

	// Add zeros, so both strings have the same length
	if (minuend.length() > subtrahend.length()) {
		int64 len = minuend.length() - subtrahend.length();
		subtrahend.insert(0, len, '0');
	}
	else if (minuend.length() < subtrahend.length()) {
		int64 len = subtrahend.length() - minuend.length();
		minuend.insert(0, len, '0');
	}

	std::string difference = "";

	// Subtract single digits from each other
	int carrier = 0;
	for (int64 i = minuend.length() - 1; i >= 0; i--) {
		int temp = minuend[i] - subtrahend[i] - carrier;

		if (temp < 0) {
			temp = temp + 2;
			carrier = 1;
		}
		else {
			carrier = 0;
		}

		difference.insert(0, std::to_string(temp));
	}

	difference = removeLeadingZeros(difference);
	return difference;
}

std::string Binary::mult_b(std::string factor1, std::string factor2) {

	// Input sanitization
	if (!isBinary(factor1) || !isBinary(factor2)) {
		std::cout << "Error: Strings may only contain positive binary numbers!" << "\n";
		return "";
	}

	// Vector which will store simple multiplication strings
	std::vector<std::string> resultSet(factor1.length());

	// Multiply single digits with each other
	int carrier = 0;
	for (int64 i = factor1.length() - 1; i >= 0; i--) {
		std::string tempStr = "";

		// Add zeros if i < factor1.length() - 1
		for (uint64 z = 0; z < factor1.length() - i - 1; z++) {
			tempStr.insert(0, "0");
		}

		for (int64 j = factor2.length() - 1; j >= 0; j--) {

			int temp = (factor1[i] - 48) * (factor2[j] - 48) + carrier;
			if (temp > 1) {
				temp = 1;
				carrier = 1;
			}
			else {
				carrier = 0;
			}

			tempStr.insert(0, std::to_string(temp));
		}

		// Insert carrier
		if (carrier == 1) {
			tempStr.insert(0, std::to_string(carrier));
			carrier = 0;
		}
		resultSet[factor1.length() - i - 1] = tempStr;
	}

	// Add simple multiplication strings together
	std::string product = "0";
	for (uint64 i = 0; i < resultSet.size(); i++) {
		product = add_b(product, resultSet[i]);
	}

	return product;
}

std::string Binary::div_b(std::string dividend, std::string divisor) {

	// Input sanitization
	if (!isBinary(dividend) || !isBinary(divisor)) {
		std::cout << "Error: Strings may only contain positive binary numbers!" << "\n";
		return "";
	}
	else if (isZero(divisor)) {
		return "Error: Division by 0 not allowed!";
	}
	else if (isZero(dividend)) {
		return "0";
	}

	// Remove leading zeros on both strings
	dividend = removeLeadingZeros(dividend);
	divisor = removeLeadingZeros(divisor);

	std::string quotient = "0";

	// Division
	while (dividend == max_b(dividend, divisor) || max_b(dividend, divisor) == "") {
		dividend = sub_b(dividend, divisor);
		quotient = add_b(quotient, "1");
	}

	return quotient;
}

std::string Binary::min_b(std::string str1, std::string str2) {

	// Input sanitization
	if (!isBinary(str1) || !isBinary(str2)) {
		std::cout << "Error: Strings may only contain positive binary numbers!" << "\n";
		return "";
	}

	// Remove leading zeros on both strings
	str1 = removeLeadingZeros(str1);
	str2 = removeLeadingZeros(str2);

	if (str1.length() < str2.length()) {
		return str1;
	}
	else if (str1.length() > str2.length()) {
		return str2;
	}

	for (uint64 i = 0; i < str1.length(); i++) {
		if (str1[i] < str2[i]) {
			return str1;
		}
		else if (str1[i] > str2[i]) {
			return str2;
		}
	}

	return "";
}

std::string Binary::max_b(std::string str1, std::string str2) {

	// Input sanitization
	if (!isBinary(str1) || !isBinary(str2)) {
		std::cout << "Error: Strings may only contain positive binary numbers!" << "\n";
		return "";
	}

	// Remove leading zeros on both strings
	str1 = removeLeadingZeros(str1);
	str2 = removeLeadingZeros(str2);

	if (str1.length() > str2.length()) {
		return str1;
	}
	else if (str1.length() < str2.length()) {
		return str2;
	}

	for (uint64 i = 0; i < str1.length(); i++) {
		if (str1[i] > str2[i]) {
			return str1;
		}
		else if (str1[i] < str2[i]) {
			return str2;
		}
	}

	return "";
}

bool Binary::isBinary(std::string string) {

	if (string.empty()) {
		std::cout << "Error: Strings may not be empty!";
		return false;
	}

	for (uint64 i = 0; i < string.length(); i++) {
		if (string[i] < '0' || string[i] > '1') {
			return false;
		}
	}

	return true;
}
