// Copyright (c) 2021 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include "stringcalc.h"

using namespace StringCalc;

std::string Hexadecimal::add_h(std::string addend1, std::string addend2) {

	// Input sanitization
	if (!isHexadecimal(addend1) || !isHexadecimal(addend2)) {
		std::cout << "Error: Strings may only contain positive hexadecimal numbers!" << "\n";
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
		int temp = charToInt(addend1[i]) + charToInt(addend2[i]) + carrier;

		if (temp > 15) {
			carrier = 1;
			temp = temp % 16;
		}
		else {
			carrier = 0;
		}

		sum.insert(0, intToString(temp));
	}

	// Insert carrier
	if (carrier == 1) {
		sum.insert(0, std::to_string(carrier));
	}

	sum = removeLeadingZeros(sum);
	return sum;
}

std::string Hexadecimal::sub_h(std::string minuend, std::string subtrahend) {

	// Input sanitization
	if (!isHexadecimal(minuend) || !isHexadecimal(subtrahend)) {
		std::cout << "Error: Strings may only contain positive hexadecimal numbers!" << "\n";
		return "";
	}

	// Negative difference
	if (subtrahend == max_h(minuend, subtrahend)) {
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
		int temp = charToInt(minuend[i]) - charToInt(subtrahend[i]) - carrier;

		if (temp < 0) {
			temp = temp + 16;
			carrier = 1;
		}
		else {
			carrier = 0;
		}

		difference.insert(0, intToString(temp));
	}

	difference = removeLeadingZeros(difference);
	return difference;
}

std::string Hexadecimal::mult_h(std::string factor1, std::string factor2) {

	// Input sanitization
	if (!isHexadecimal(factor1) || !isHexadecimal(factor2)) {
		std::cout << "Error: Strings may only contain positive hexadecimal numbers!" << "\n";
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

			int temp = charToInt(factor1[i]) * charToInt(factor2[j]) + carrier;
			if (temp > 16) {
				carrier = (temp - (temp % 16)) / 16;
				temp = temp % 16;
			}
			else {
				carrier = 0;
			}

			tempStr.insert(0, intToString(temp));
		}

		// Insert carrier
		if (carrier != 0) {
			tempStr.insert(0, intToString(carrier));
			carrier = 0;
		}
		resultSet[factor1.length() - i - 1] = tempStr;
	}

	// Add simple multiplication strings together
	std::string product = "0";
	for (uint64 i = 0; i < resultSet.size(); i++) {
		product = add_h(product, resultSet[i]);
	}

	return product;
}

std::string Hexadecimal::div_h(std::string dividend, std::string divisor) {

	// Input sanitization
	if (!isHexadecimal(dividend) || !isHexadecimal(divisor)) {
		std::cout << "Error: Strings may only contain positive hexadecimal numbers!" << "\n";
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
	while (dividend == max_h(dividend, divisor) || max_h(dividend, divisor) == "") {
		dividend = sub_h(dividend, divisor);
		quotient = add_h(quotient, "1");
	}

	return quotient;
}

std::string Hexadecimal::min_h(std::string str1, std::string str2) {

	// Input sanitization
	if (!isHexadecimal(str1) || !isHexadecimal(str2)) {
		std::cout << "Error: Strings may only contain positive hexadecimal numbers!" << "\n";
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
		if (charToInt(str1[i]) < charToInt(str2[i])) {
			return str1;
		}
		else if (charToInt(str1[i]) > charToInt(str2[i])) {
			return str2;
		}
	}

	return "";
}

std::string Hexadecimal::max_h(std::string str1, std::string str2) {

	// Input sanitization
	if (!isHexadecimal(str1) || !isHexadecimal(str2)) {
		std::cout << "Error: Strings may only contain positive hexadecimal numbers!" << "\n";
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
		if (charToInt(str1[i]) > charToInt(str2[i])) {
			return str1;
		}
		else if (charToInt(str1[i]) < charToInt(str2[i])) {
			return str2;
		}
	}

	return "";
}

int Hexadecimal::letterToInt(char c) {

	if (c >= '0' && c <= '9') {
		return c - 48;
	}
	else if ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) {
		return (c % 16) + 9;
	}

	std::cout << "Error: Couldn't convert char correctly to int.";
	return -1;
}

std::string Hexadecimal::intToLetter(int num) {

	// 0 to 9
	if (num >= 0 && num <= 9) {
		return std::to_string(num);
	}
	// A to F
	else if (num >= 10 && num <= 15) {
		char c = num + 55;
		std::string s;
		s += c;
		return s;
	}

	std::cout << "Error: Couldn't convert int correctly to string.";
	return "";
}

bool Hexadecimal::isHexadecimal(std::string string) {

	if (string.empty()) {
		std::cout << "Error: Strings may not be empty!";
		return false;
	}

	for (uint64 i = 0; i < string.length(); i++) {
		if ((string[i] < '0' || string[i] > '9') &&
			(string[i] < 'A' || string[i] > 'F') &&
			(string[i] < 'a' || string[i] > 'f')) {
			return false;
		}
	}

	return true;
}
