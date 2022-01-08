// Copyright (c) 2021 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include "stringcalc.h"

using namespace StringCalc;

std::string Decimal::add(std::string addend1, std::string addend2) {

	// Input sanitization
	if (!isDecimal(addend1) || !isDecimal(addend2)) {
		std::cout << "Error: Strings may only contain positive decimal numbers!" << "\n";
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

		if (temp > 9) {
			carrier = 1;
			temp = temp % 10;
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

std::string Decimal::sub(std::string minuend, std::string subtrahend) {

	// Input sanitization
	if (!isDecimal(minuend) || !isDecimal(subtrahend)) {
		std::cout << "Error: Strings may only contain positive decimal numbers!" << "\n";
		return "";
	}

	// Negative difference
	if (subtrahend == max(minuend, subtrahend)) {
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
			temp = temp + 10;
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

std::string Decimal::mult(std::string factor1, std::string factor2) {

	// Input sanitization
	if (!isDecimal(factor1) || !isDecimal(factor2)) {
		std::cout << "Error: Strings may only contain positive decimal numbers!" << "\n";
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
			if (temp > 9) {
				carrier = temp / 10;
				temp = temp % 10;
			}
			else {
				carrier = 0;
			}

			tempStr.insert(0, std::to_string(temp));
		}

		// Insert carrier
		if (carrier != 0) {
			tempStr.insert(0, std::to_string(carrier));
			carrier = 0;
		}
		resultSet[factor1.length() - i - 1] = tempStr;
	}

	// Add simple multiplication strings together
	std::string product = "0";
	for (uint64 i = 0; i < resultSet.size(); i++) {
		product = add(product, resultSet[i]);
	}

	return product;
}

std::string Decimal::div(std::string dividend, std::string divisor) {

	// Input sanitization
	if (!isDecimal(dividend) || !isDecimal(divisor)) {
		std::cout << "Error: Strings may only contain positive decimal numbers!" << "\n";
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
	while (dividend == max(dividend, divisor) || max(dividend, divisor) == "") {
		dividend = sub(dividend, divisor);
		quotient = add(quotient, "1");
	}

	return quotient;
}

std::string Decimal::mod(std::string dividend, std::string divisor) {

	// Input sanitization
	if (!isDecimal(dividend) || !isDecimal(divisor)) {
		std::cout << "Error: Strings may only contain positive decimal numbers!" << "\n";
		return "";
	}
	else if (isZero(divisor)) {
		std::cout << "Error: Modular arithmetic with 0 not allowed!";
		return "";
	}

	std::string quotient = div(dividend, divisor);
	std::string remainder = sub(dividend, mult(divisor, quotient));

	return remainder;
}

std::string Decimal::pow(std::string base, std::string exponent) {

	// Input sanitization
	if (!isDecimal(base) || !isDecimal(exponent)) {
		std::cout << "Error: Strings may only contain positive decimal numbers!" << "\n";
		return "";
	}
	else if (isZero(base) && isZero(exponent)) {
		std::cout << "Error: 0 ^ 0 is not defined!";
		return "";
	}

	std::string power = "1";

	while (exponent != "0") {
		power = mult(power, base);
		exponent = sub(exponent, "1");
	}

	return power;
}

std::string Decimal::fact(std::string num) {

	// Input sanitization
	if (!isDecimal(num)) {
		std::cout << "Error: Strings may only contain positive decimal numbers!" << "\n";
		return "";
	}

	std::string factorial = "1";

	while (num != "0") {
		factorial = mult(factorial, num);
		num = sub(num, "1");
	}

	return factorial;
}

std::string Decimal::min(std::string str1, std::string str2) {

	// Input sanitization
	if (!isDecimal(str1) || !isDecimal(str2)) {
		std::cout << "Error: Strings may only contain positive decimal numbers!" << "\n";
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

std::string Decimal::max(std::string str1, std::string str2) {

	// Input sanitization
	if (!isDecimal(str1) || !isDecimal(str2)) {
		std::cout << "Error: Strings may only contain positive decimal numbers!" << "\n";
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

bool Decimal::isDecimal(std::string string) {

	if (string.empty()) {
		std::cout << "Error: Strings may not be empty!";
		return false;
	}

	for (uint64 i = 0; i < string.length(); i++) {
		if (string[i] < '0' || string[i] > '9') {
			return false;
		}
	}

	return true;
}
