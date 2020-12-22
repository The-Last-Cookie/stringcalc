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

std::string Decimal::add(std::string addend1, std::string addend2) {
	
	// Input sanitization
	if (!Decimal::isDecimal(addend1) || !Decimal::isDecimal(addend2)) {
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

	return sum;
}

std::string Decimal::sub(std::string minuend, std::string subtrahend) {
	
	// Input sanitization
	if (!Decimal::isDecimal(minuend) || !Decimal::isDecimal(subtrahend)) {
		std::cout << "Error: Strings may only contain positive decimal numbers!" << "\n";
		return "";
	}
	else if (isZero(subtrahend)) {
		return minuend;
	}
	else if (minuend == subtrahend) {
		return "0";
	}

	// Negative difference
	if (subtrahend == StringCalc::Decimal::max(minuend, subtrahend)) {
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
		int temp = minuend[i] - subtrahend[i] - carrier;

		if (temp < 0) {
			temp = 10 + minuend[i] - subtrahend[i] - carrier;
			carrier = 1;
		}
		else {
			carrier = 0;
		}

		difference.insert(0, std::to_string(temp));
	}

	for (int i = 0; i < difference.length(); i++) {
		if (difference[0] == '0') {
			difference.erase(0, 1);
			
			// In case difference contains several zeros
			i--;
		}
		else {
			break;
		}
	}

	return difference;
}

std::string Decimal::mult(std::string factor1, std::string factor2) {
	
	// Input sanitization
	if (!Decimal::isDecimal(factor1) || !Decimal::isDecimal(factor2)) {
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
				std::div_t digit = std::div(temp, 10);
				temp = ((factor1[i] - 48) * (factor2[j] - 48) + carrier) % 10;
				carrier = (int) digit.quot;
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
	while (singleResults.size() > 1) {
		singleResults[1] = StringCalc::Decimal::add(singleResults[0], singleResults[1]);

		std::vector<std::string>::iterator it;
		it = singleResults.begin();
		singleResults.erase(it);
	}
	
	std::string product = singleResults.at(0);
	return product;
}

std::string Decimal::div(std::string dividend, std::string divisor) {
	
	// Input sanitization
	if (!Decimal::isDecimal(dividend) || !Decimal::isDecimal(divisor)) {
		std::cout << "Error: Strings may only contain positive decimal numbers!" << "\n";
		return "";
	}
	else if (isZero(divisor)) {
		return "Error: Division by 0 not allowed!";
	}
	else if (isZero(dividend)) {
		return "0";
	}

	int counter = 0;

	// Division
	while (dividend == StringCalc::Decimal::max(dividend, divisor) || StringCalc::Decimal::max(dividend, divisor) == "") {
		dividend = sub(dividend, divisor);
		counter++;
	}

	std::string quotient = std::to_string(counter);
	return quotient;
}

std::string Decimal::pow(std::string base, std::string exponent) {
	
	// Input sanitization
	if (!Decimal::isDecimal(base) || !Decimal::isDecimal(exponent)) {
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
		power = StringCalc::Decimal::mult(power, base);
		exponent = StringCalc::Decimal::sub(exponent, "1");
	}
	
	return power;
}

std::string Decimal::fact(std::string num) {

	// Input sanitization
	if (!Decimal::isDecimal(num)) {
		std::cout << "Error: Strings may only contain positive decimal numbers!" << "\n";
		return "";
	}
	else if (isZero(num)) {
		return "1";
	}

	std::string factorial = "1";

	while (num != "0") {
		factorial = StringCalc::Decimal::mult(factorial, num);
		num = StringCalc::Decimal::sub(num, "1");
	}

	return factorial;
}

std::string Decimal::max(std::string str1, std::string str2) {
	
	// Input sanitization
	if (!Decimal::isDecimal(str1) || !Decimal::isDecimal(str2)) {
		std::cout << "Error: Strings may only contain positive decimal numbers!" << "\n";
		return "";
	}
	
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
	if (!Binary::isBinary(addend1) || !Binary::isBinary(addend2)) {
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

	return sum;
}

std::string Binary::sub_b(std::string minuend, std::string subtrahend) {
	
	// Input sanitization
	if (!Binary::isBinary(minuend) || !Binary::isBinary(subtrahend)) {
		std::cout << "Error: Strings may only contain positive binary numbers!" << "\n";
		return "";
	}
	else if (isZero(subtrahend)) {
		return minuend;
	}

	// Negative difference
	if (subtrahend == StringCalc::Binary::max_b(minuend, subtrahend)) {
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

	// Remove leading zeros
	for (int i = 0; i < difference.length()- 1; i++) {
		if (difference[0] == '0') {
			difference.erase(0, 1);

			// In case difference contains several zeros
			i--;
		}
		else {
			break;
		}
	}

	return difference;
}

std::string Binary::mult_b(std::string factor1, std::string factor2) {
	
	// Input sanitization
	if (!Binary::isBinary(factor1) || !Binary::isBinary(factor2)) {
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
	while (singleResults.size() > 1) {
		singleResults[1] = StringCalc::Binary::add_b(singleResults[0], singleResults[1]);

		std::vector<std::string>::iterator it;
		it = singleResults.begin();
		singleResults.erase(it);
	}

	std::string product = singleResults.at(0);
	return product;
}

std::string Binary::div_b(std::string dividend, std::string divisor){
	
	// Input sanitization
	if (!Binary::isBinary(dividend) || !Binary::isBinary(divisor)) {
		std::cout << "Error: Strings may only contain positive binary numbers!" << "\n";
		return "";
	}
	else if (isZero(divisor)) {
		return "Error: Division by 0 not allowed!";
	}
	else if (isZero(dividend)) {
		return "0";
	}

	std::string quotient = "0";

	// Division
	while (dividend == StringCalc::Binary::max_b(dividend, divisor) || StringCalc::Binary::max_b(dividend, divisor) == "") {
		dividend = sub_b(dividend, divisor);
		quotient = StringCalc::Binary::add_b(quotient, "1");
	}

	return quotient;
}

std::string Binary::max_b(std::string str1, std::string str2) {
	
	// Input sanitization
	if (!Binary::isBinary(str1) || !Binary::isBinary(str2)) {
		std::cout << "Error: Strings may only contain positive binary numbers!" << "\n";
		return "";
	}

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
	if (!Hexadecimal::isHexadecimal(addend1) || !Hexadecimal::isHexadecimal(addend2)) {
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

	return sum;
}

std::string Hexadecimal::sub_h(std::string minuend, std::string subtrahend) {

	// Input sanitization
	if (!Hexadecimal::isHexadecimal(minuend) || !Hexadecimal::isHexadecimal(subtrahend)) {
		std::cout << "Error: Strings may only contain positive hexadecimal numbers!" << "\n";
		return "";
	}
	else if (isZero(subtrahend)) {
		return minuend;
	}

	// Negative difference
	if (subtrahend == StringCalc::Hexadecimal::max_h(minuend, subtrahend)) {
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

	// Remove leading zeros
	for (int i = 0; i < difference.length() - 1; i++) {
		if (difference[0] == '0') {
			difference.erase(0, 1);

			// In case difference contains several zeros
			i--;
		}
		else {
			break;
		}
	}

	return difference;
}

std::string Hexadecimal::mult_h(std::string factor1, std::string factor2) {

	// Input sanitization
	if (!Hexadecimal::isHexadecimal(factor1) || !Hexadecimal::isHexadecimal(factor2)) {
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
	while (singleResults.size() > 1) {
		singleResults[1] = StringCalc::Hexadecimal::add_h(singleResults[0], singleResults[1]);

		std::vector<std::string>::iterator it;
		it = singleResults.begin();
		singleResults.erase(it);
	}

	std::string product = singleResults.at(0);
	return product;
}

std::string Hexadecimal::div_h(std::string dividend, std::string divisor) {

	// Input sanitization
	if (!Hexadecimal::isHexadecimal(dividend) || !Hexadecimal::isHexadecimal(divisor)) {
		std::cout << "Error: Strings may only contain positive hexadecimal numbers!" << "\n";
		return "";
	}
	else if (isZero(divisor)) {
		return "Error: Division by 0 not allowed!";
	}
	else if (isZero(dividend)) {
		return "0";
	}

	std::string quotient = "0";

	// Division
	while (dividend == StringCalc::Hexadecimal::max_h(dividend, divisor) || StringCalc::Hexadecimal::max_h(dividend, divisor) == "") {
		dividend = sub_h(dividend, divisor);
		quotient = StringCalc::Hexadecimal::add_h(quotient, "1");
	}

	return quotient;
}

std::string Hexadecimal::max_h(std::string str1, std::string str2) {

	// Input sanitization
	if (!Hexadecimal::isHexadecimal(str1) || !Hexadecimal::isHexadecimal(str2)) {
		std::cout << "Error: Strings may only contain positive hexadecimal numbers!" << "\n";
		return "";
	}

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
