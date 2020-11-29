// Copyright (c) 2020 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include "stringcalc.h"

using namespace StringCalc;

std::string Decimal::add(std::string addend1, std::string addend2) {
	
	// Input sanitization
	if (!std::regex_match(addend1, std::regex("[0-9]+")) || !std::regex_match(addend2, std::regex("[0-9]+"))) {
		std::cout << "Error: Strings may only contain positive numbers!" << "\n";
		return "";
	}
	else if (addend1 == "0") {
		return addend2;
	}
	else if (addend2 == "0") {
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
	if (!std::regex_match(minuend, std::regex("[0-9]+")) || !std::regex_match(subtrahend, std::regex("[0-9]+"))) {
		std::cout << "Error: Strings may only contain positive numbers!";
		return "";
	}
	else if (subtrahend == "0") {
		return minuend;
	}
	else if (minuend == "0") {
		return "-" + subtrahend;
	}
	else if (minuend == subtrahend) {
		return "0";
	}

	// In case the difference would be negative, switch numbers
	if (subtrahend == StringCalc::Decimal::max(minuend, subtrahend)) {
		return "-" + sub(subtrahend, minuend);
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
		}
		else {
			break;
		}
	}

	return difference;
}

std::string Decimal::mult(std::string factor1, std::string factor2) {
	
	// Input sanitization
	if (!std::regex_match(factor1, std::regex("[0-9]+")) || !std::regex_match(factor2, std::regex("[0-9]+"))) {
		std::cout << "Error: Strings may only contain positive numbers!" << "\n";
		return "";
	}
	else if (factor1.empty() || factor1 == "0" || factor2.empty() || factor2 == "0") {
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
	if (!std::regex_match(dividend, std::regex("[0-9]+")) || !std::regex_match(divisor, std::regex("[0-9]+"))) {
		std::cout << "Error: Strings may only contain positive numbers!" << "\n";
		return "";
	}
	else if (divisor.empty() || divisor == "0") {
		return "Error: Division by 0 not allowed!";
	}
	else if (dividend.empty() || dividend == "0") {
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
	if (!std::regex_match(base, std::regex("[0-9]+")) || !std::regex_match(exponent, std::regex("[0-9]+"))) {
		std::cout << "Error: Strings may only contain positive numbers!" << "\n";
		return "";
	}
	else if (base == "" || base == "0") {
		return "0";
	}
	else if (exponent == "" || exponent == "0") {
		return "1";
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
	if (!std::regex_match(num, std::regex("[0-9]+"))) {
		std::cout << "Error: Strings may only contain positive numbers!" << "\n";
		return "";
	}
	else if (num == "" || num == "0") {
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
	if (!std::regex_match(str1, std::regex("[0-9]+")) || !std::regex_match(str2, std::regex("[0-9]+"))) {
		std::cout << "Error: Strings may only contain positive numbers!";
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

std::string Binary::add_b(std::string addend1, std::string addend2) {
	
	// Input sanitization
	if (!std::regex_match(addend1, std::regex("[0-1]+")) || !std::regex_match(addend2, std::regex("[0-1]+"))) {
		std::cout << "Error: Strings may only contain positive numbers!" << "\n";
		return "";
	}
	else if (addend1 == "0") {
		return addend2;
	}
	else if (addend2 == "0") {
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
	if (!std::regex_match(minuend, std::regex("[0-1]+")) || !std::regex_match(subtrahend, std::regex("[0-1]+"))) {
		std::cout << "Error: Strings may only contain positive numbers!";
		return "";
	}
	else if (subtrahend == "0") {
		return minuend;
	}
	else if (minuend == subtrahend) {
		return "0";
	}

	// Negative difference
	if (subtrahend == StringCalc::Decimal::max(minuend, subtrahend)) {
		std::cout << "Error: Negative results not allowed.";
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
			temp = (temp % 2) * (-1);
			carrier = 1;
		}
		else {
			carrier = 0;
		}

		difference.insert(0, std::to_string(temp));
	}

	// Remove leading zeros
	for (int i = 0; i < difference.length(); i++) {
		if (difference[0] == '0') {
			difference.erase(0, 1);
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
	if (!std::regex_match(factor1, std::regex("[0-1]+")) || !std::regex_match(factor2, std::regex("[0-1]+"))) {
		std::cout << "Error: Strings may only contain positive numbers!" << "\n";
		return "";
	}
	else if (factor1.empty() || factor1 == "0" || factor2.empty() || factor2 == "0") {
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
	if (!std::regex_match(dividend, std::regex("[0-1]+")) || !std::regex_match(divisor, std::regex("[0-1]+"))) {
		std::cout << "Error: Strings may only contain positive numbers!" << "\n";
		return "";
	}
	else if (divisor.empty() || divisor == "0") {
		return "Error: Division by 0 not allowed!";
	}
	else if (dividend.empty() || dividend == "0") {
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
	if (!std::regex_match(str1, std::regex("[0-1]+")) || !std::regex_match(str2, std::regex("[0-1]+"))) {
		std::cout << "Error: Strings may only contain positive numbers!";
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
