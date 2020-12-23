// Copyright (c) 2020 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include "stringcalc.h"

using namespace StringCalc;

bool StringCalc::isZero(std::string string) {
	
	if (std::regex_match(string, std::regex("[0]+"))) {
		return true;
	}

	return false;
}

std::string StringCalc::removeLeadingZeros(std::string str) {

	int counter = 0;
	for (int i = 0; i < str.length() - 1; i++) {
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

std::string Decimal::add(std::string addend1, std::string addend2) {
	
	// Input sanitization
	if (!isDecimal(addend1) || !isDecimal(addend2)) {
		std::cout << "Error: Strings may only contain positive decimal numbers!" << "\n";
		return "";
	}
	else if (isZero(addend1)) {
		return addend2;
	}
	else if (isZero(addend2)) {
		return addend1;
	}

	// Add zeros, so both strings have the same length
	if (addend1.length() > addend2.length()) {
		int len = addend1.length() - addend2.length();
		addend2.insert(0, len, '0');
	}
	else if (addend1.length() < addend2.length()) {
		int len = addend2.length() - addend1.length();
		addend1.insert(0, len, '0');
	}

	std::string sum = "";

	// Add single digits together
	int carrier = 0;
	for (int i = addend1.length() - 1; i >= 0; i--) {
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
	else if (isZero(subtrahend)) {
		return minuend;
	}

	// Negative difference
	if (subtrahend == max(minuend, subtrahend)) {
		std::cout << "Error: Result may only be positive!";
		return "";
	}

	// Add zeros, so both strings have the same length
	if (minuend.length() > subtrahend.length()) {
		int len = minuend.length() - subtrahend.length();
		subtrahend.insert(0, len, '0');
	}
	else if (minuend.length() < subtrahend.length()) {
		int len = subtrahend.length() - minuend.length();
		minuend.insert(0, len, '0');
	}

	std::string difference = "";

	// Subtract single digits from each other
	int carrier = 0;
	for (int i = minuend.length() - 1; i >= 0; i--) {
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
	else if (isZero(factor1) || isZero(factor2)) {
		return "0";
	}

	// Vector which will store simple multiplication strings
	std::vector<std::string> singleResults;

	// Multiply single digits with each other
	int carrier = 0;
	for (int i = factor1.length() - 1; i >= 0; i--) {
		std::string tempStr = "";
		
		// Add zeros if i < factor1.length() - 1
		for (int z = 0; z < factor1.length() - i - 1; z++) {
			tempStr.insert(0, "0");
		}

		for (int j = factor2.length() - 1; j >= 0; j--) {
			
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

		if (carrier != 0) {
			tempStr.insert(0, std::to_string(carrier));
			carrier = 0;
		}
		singleResults.push_back(tempStr);
	}
	
	// Add simple multiplication strings together
	std::string product = "0";
	for (int i = 0; i < singleResults.size(); i++) {
		product = add(product, singleResults[i]);
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

	std::string counter = "0";

	// Division
	while (dividend == max(dividend, divisor) || max(dividend, divisor) == "") {
		dividend = sub(dividend, divisor);
		counter = add(counter, "1");
	}

	std::string quotient = counter;
	return quotient;
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
	else if (isZero(base)) {
		return "0";
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
	else if (isZero(num)) {
		return "1";
	}

	std::string factorial = "1";

	while (num != "0") {
		factorial = mult(factorial, num);
		num = sub(num, "1");
	}

	return factorial;
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

	for (int i = 0; i < str1.length(); i++) {
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

	if (std::regex_match(string, std::regex("[0-9]+"))) {
		return true;
	}

	return false;
}

std::string Binary::add_b(std::string addend1, std::string addend2) {
	
	// Input sanitization
	if (!isBinary(addend1) || !isBinary(addend2)) {
		std::cout << "Error: Strings may only contain positive binary numbers!" << "\n";
		return "";
	}
	else if (isZero(addend1)) {
		return addend2;
	}
	else if (isZero(addend2)) {
		return addend1;
	}

	// Add zeros, so both strings have the same length
	if (addend1.length() > addend2.length()) {
		int len = addend1.length() - addend2.length();
		addend2.insert(0, len, '0');
	}
	else if (addend1.length() < addend2.length()) {
		int len = addend2.length() - addend1.length();
		addend1.insert(0, len, '0');
	}

	std::string sum = "";

	// Add single digits together
	int carrier = 0;
	for (int i = addend1.length() - 1; i >= 0; i--) {
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
	else if (isZero(subtrahend)) {
		return minuend;
	}

	// Negative difference
	if (subtrahend == max_b(minuend, subtrahend)) {
		std::cout << "Error: Result may only be positive!";
		return "";
	}

	// Add zeros, so both strings have the same length
	if (minuend.length() > subtrahend.length()) {
		int len = minuend.length() - subtrahend.length();
		subtrahend.insert(0, len, '0');
	}
	else if (minuend.length() < subtrahend.length()) {
		int len = subtrahend.length() - minuend.length();
		minuend.insert(0, len, '0');
	}

	std::string difference = "";

	// Subtract single digits from each other
	int carrier = 0;
	for (int i = minuend.length() - 1; i >= 0; i--) {
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
	else if (isZero(factor1) || isZero(factor2)) {
		return "0";
	}

	// Vector which will store simple multiplication strings
	std::vector<std::string> singleResults;

	// Multiply single digits with each other
	int carrier = 0;
	for (int i = factor1.length() - 1; i >= 0; i--) {
		std::string tempStr = "";

		// Add zeros if i < factor1.length() - 1
		for (int z = 0; z < factor1.length() - i - 1; z++) {
			tempStr.insert(0, "0");
		}

		for (int j = factor2.length() - 1; j >= 0; j--) {

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

		if (carrier == 1) {
			tempStr.insert(0, std::to_string(carrier));
			carrier = 0;
		}
		singleResults.push_back(tempStr);
	}

	// Add simple multiplication strings together
	std::string product = "0";
	for (int i = 0; i < singleResults.size(); i++) {
		product = add_b(product, singleResults[i]);
	}

	return product;
}

std::string Binary::div_b(std::string dividend, std::string divisor){
	
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

	for (int i = 0; i < str1.length(); i++) {
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
	
	if (std::regex_match(string, std::regex("[0-1]+"))) {
		return true;
	}

	return false;
}

std::string Hexadecimal::add_h(std::string addend1, std::string addend2) {

	// Input sanitization
	if (!isHexadecimal(addend1) || !isHexadecimal(addend2)) {
		std::cout << "Error: Strings may only contain positive hexadecimal numbers!" << "\n";
		return "";
	}
	else if (isZero(addend1)) {
		return addend2;
	}
	else if (isZero(addend2)) {
		return addend1;
	}

	// Add zeros, so both strings have the same length
	if (addend1.length() > addend2.length()) {
		int len = addend1.length() - addend2.length();
		for (int i = 0; i < len; i++) {
			addend2.insert(0, "0");
		}
	}
	else if (addend1.length() < addend2.length()) {
		int len = addend2.length() - addend1.length();
		for (int i = 0; i < len; i++) {
			addend1.insert(0, "0");
		}
	}

	std::string sum = "";

	// Add single digits together
	int carrier = 0;
	for (int i = addend1.length() - 1; i >= 0; i--) {
		int temp = Hexadecimal::letterToInt(addend1[i]) + Hexadecimal::letterToInt(addend2[i]) + carrier;

		if (temp > 15) {
			carrier = 1;
			temp = temp % 16;
		}
		else {
			carrier = 0;
		}

		sum.insert(0, Hexadecimal::intToLetter(temp));
	}

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
	else if (isZero(subtrahend)) {
		return minuend;
	}

	// Negative difference
	if (subtrahend == max_h(minuend, subtrahend)) {
		std::cout << "Error: Result may only be positive!";
		return "";
	}

	// Add zeros, so both strings have the same length
	if (minuend.length() > subtrahend.length()) {
		int len = minuend.length() - subtrahend.length();
		for (int i = 0; i < len; i++) {
			subtrahend.insert(0, "0");
		}
	}
	else if (minuend.length() < subtrahend.length()) {
		int len = subtrahend.length() - minuend.length();
		for (int i = 0; i < len; i++) {
			minuend.insert(0, "0");
		}
	}

	std::string difference = "";

	// Subtract single digits from each other
	int carrier = 0;
	for (int i = minuend.length() - 1; i >= 0; i--) {
		int temp = Hexadecimal::letterToInt(minuend[i]) - Hexadecimal::letterToInt(subtrahend[i]) - carrier;

		if (temp < 0) {
			temp = temp + 16;
			carrier = 1;
		}
		else {
			carrier = 0;
		}

		difference.insert(0, Hexadecimal::intToLetter(temp));
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
	else if (isZero(factor1) || isZero(factor2)) {
		return "0";
	}

	// Vector which will store simple multiplication strings
	std::vector<std::string> singleResults;

	// Multiply single digits with each other
	int carrier = 0;
	for (int i = factor1.length() - 1; i >= 0; i--) {
		std::string tempStr = "";

		// Add zeros if i < factor1.length() - 1
		for (int z = 0; z < factor1.length() - i - 1; z++) {
			tempStr.insert(0, "0");
		}

		for (int j = factor2.length() - 1; j >= 0; j--) {

			int temp = Hexadecimal::letterToInt(factor1[i]) * Hexadecimal::letterToInt(factor2[j]) + carrier;
			if (temp > 16) {
				carrier = (temp - (temp % 16)) / 16;
				temp = temp % 16;
			}
			else {
				carrier = 0;
			}

			tempStr.insert(0, Hexadecimal::intToLetter(temp));
		}

		if (carrier != 0) {
			tempStr.insert(0, Hexadecimal::intToLetter(carrier));
			carrier = 0;
		}
		singleResults.push_back(tempStr);
	}

	// Add simple multiplication strings together
	std::string product = "0";
	for (int i = 0; i < singleResults.size(); i++) {
		product = add_h(product, singleResults[i]);
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

	for (int i = 0; i < str1.length(); i++) {
		if (Hexadecimal::letterToInt(str1[i]) > Hexadecimal::letterToInt(str2[i])) {
			return str1;
		}
		else if (Hexadecimal::letterToInt(str1[i]) < Hexadecimal::letterToInt(str2[i])) {
			return str2;
		}
	}

	return "";
}

int Hexadecimal::letterToInt(char c) {
	
	// 0 to 9
	if (c >= 48 && c <= 57) {
		return c - 48;
	}
	// A to F and a to f
	else if ((c >= 65 && c <= 70) || (c >= 97 && c <= 102)) {
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

	if (std::regex_match(string, std::regex("[0-9A-Fa-f]+"))) {
		return true;
	}

	return false;
}
