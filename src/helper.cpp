// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include "helper.h"
#include "stringcalc.h"

using namespace StringCalc;

std::string StringCalc::Helper::intToString(int num) {
	// 0 to 9
	if (num >= 0 && num <= 9) {
		char c = num + 48;
		std::string s;
		s = c;
		return s;
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

int StringCalc::Helper::charToInt(char c) {
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

std::string StringCalc::Helper::min(std::string str1, std::string str2) {
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

std::string StringCalc::Helper::max(std::string str1, std::string str2) {
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

std::string StringCalc::Helper::removeLeadingZeros(std::string str) {
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

std::string StringCalc::Helper::h_add(unsigned int base, std::string addend1, std::string addend2) {
	std::string sum = "";

	int carrier = 0;
	for (int64 i = addend1.length() - 1; i >= 0; i--) {
		int temp = charToInt(addend1[i]) + charToInt(addend2[i]) + carrier;

		if (temp > (base - 1)) {
			carrier = 1;
			temp = temp % base;
		}
		else {
			carrier = 0;
		}

		sum.insert(0, intToString(temp));
	}

	// Add carrier
	if (carrier == 1) {
		sum.insert(0, "1");
	}

	sum = removeLeadingZeros(sum);
	return sum;
}

std::string StringCalc::Helper::h_sub(unsigned int base, std::string minuend, std::string subtrahend) {
	std::string difference = "";

	// Subtract single digits from each other
	int carrier = 0;
	for (int64 i = minuend.length() - 1; i >= 0; i--) {
		int temp = charToInt(minuend[i]) - charToInt(subtrahend[i]) - carrier;

		if (temp < 0) {
			temp = temp + base;
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

std::string StringCalc::Helper::h_mult(unsigned int base, std::string factor1, std::string factor2) {
	// Vector which will store simple multiplication strings
	std::vector<std::string> resultSet(factor1.length());

	// Multiply single digits with each other
	int carrier = 0;
	for (int64 i = factor1.length() - 1; i >= 0; i--) {
		std::string tempStr = "";

		// Add zeros if the current digit from factor1 is not a 1 digit place
		for (uint64 z = 0; z < factor1.length() - i - 1; z++) {
			tempStr.insert(0, "0");
		}

		for (int64 j = factor2.length() - 1; j >= 0; j--) {
			int temp = charToInt(factor1[i]) * charToInt(factor2[j]) + carrier;
			if (temp > (base - 1)) {
				carrier = temp / base;
				temp = temp % base;
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
		product = add(base, product, resultSet[i]);
	}

	return product;
}

std::string StringCalc::Helper::h_div(unsigned int base, std::string dividend, std::string divisor) {
	std::string quotient = "0";

	while (dividend == StringCalc::Helper::max(dividend, divisor) || StringCalc::Helper::max(dividend, divisor) == "") {
		dividend = sub(base, dividend, divisor);
		quotient = add(base, quotient, "1");
	}

	return quotient;
}

std::string StringCalc::Helper::h_mod(unsigned int base, std::string dividend, std::string divisor) {
	std::string quotient = div(base, dividend, divisor);
	std::string remainder = sub(base, dividend, h_mult(base, divisor, quotient));
	return remainder;
}

std::string StringCalc::Helper::h_pow(unsigned int base, std::string baseExp, std::string exponent) {
	std::string power = "1";

	while (exponent != "0") {
		power = mult(base, power, baseExp);
		exponent = sub(base, exponent, "1");
	}

	return power;
}

std::string StringCalc::Helper::h_fact(unsigned int base, std::string num) {
	std::string factorial = "1";

	while (num != "0") {
		factorial = mult(base, factorial, num);
		num = sub(base, num, "1");
	}

	return factorial;
}
