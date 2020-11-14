#include "stringcalc.h"

std::string StringCalc::add(std::string str1, std::string str2) {
	
	// Input sanitization
	if (!std::regex_match(str1, std::regex("[0-9]+")) || !std::regex_match(str2, std::regex("[0-9]+"))) {
		std::cout << "Error: Strings may only contain positive numbers!" << "\n";
		return "";
	}
	else if (str1 == "0") {
		return str2;
	}
	else if (str2 == "0") {
		return str1;
	}

	// Add zeros, so both strings have the same length
	if (str1.length() > str2.length()) {
		int len = str1.length() - str2.length();
		for (int i = 0; i < len; i++) {
			str2.insert(0, "0");
		}
	}
	else if (str1.length() < str2.length()) {
		int len = str2.length() - str1.length();
		for (int i = 0; i < len; i++) {
			str1.insert(0, "0");
		}
	}

	std::string result = "";

	// Add single digits together
	int carrier = 0;
	for (int i = str1.length() - 1; i >= 0; i--) {
		// ASCII value convertion
		int temp = str1[i] + str2[i] + carrier - 96;

		if (temp > 9) {
			carrier = 1;
			temp = temp % 10;
		}
		else {
			carrier = 0;
		}

		result.insert(0, std::to_string(temp));
	}

	if (carrier == 1) {
		result.insert(0, std::to_string(carrier));
	}

	return result;
}

std::string StringCalc::sub(std::string str1, std::string str2) {
	
	// Input sanitization
	if (!std::regex_match(str1, std::regex("[0-9]+")) || !std::regex_match(str2, std::regex("[0-9]+"))) {
		std::cout << "Error: Strings may only contain positive numbers!";
		return "";
	}
	else if (str2 == "0") {
		return str1;
	}
	else if (str1 == "0") {
		return "-" + str2;
	}
	else if (str1 == str2) {
		return "0";
	}

	// In case the result would be negative, switch numbers
	if (str2 == StringCalc::max(str1, str2)) {
		return "-" + sub(str2, str1);
	}

	// Add zeros, so both strings have the same length
	if (str1.length() > str2.length()) {
		int len = str1.length() - str2.length();
		for (int i = 0; i < len; i++) {
			str2.insert(0, "0");
		}
	}
	else if (str1.length() < str2.length()) {
		int len = str2.length() - str1.length();
		for (int i = 0; i < len; i++) {
			str1.insert(0, "0");
		}
	}

	std::string result = "";

	// Subtract single digits from each other
	int carrier = 0;
	for (int i = str1.length() - 1; i >= 0; i--) {
		int temp = str1[i] - str2[i] - carrier;

		if (temp < 0) {
			temp = 10 + str1[i] - str2[i] - carrier;
			carrier = 1;
		}
		else {
			carrier = 0;
		}

		result.insert(0, std::to_string(temp));
	}

	for (int i = 0; i < result.length(); i++) {
		if (result[0] == '0') {
			result.erase(0, 1);
		}
		else {
			break;
		}
	}

	return result;
}

std::string StringCalc::mult(std::string str1, std::string str2) {
	
	// Input sanitization
	if (!std::regex_match(str1, std::regex("[0-9]+")) || !std::regex_match(str2, std::regex("[0-9]+"))) {
		std::cout << "Error: Strings may only contain positive numbers!" << "\n";
		return "";
	}
	else if (str1.empty() || str1 == "0" || str2.empty() || str2 == "0") {
		return "0";
	}

	// Vector which will store simple multiplication strings
	std::vector<std::string> singleResults;

	// Multiply single digits with each other
	int carrier = 0;
	for (int i = str1.length() - 1; i >= 0; i--) {
		std::string tempStr = "";
		
		// Add zeros if i < str1.length() - 1
		for (int z = 0; z < str1.length() - i - 1; z++) {
			tempStr.insert(0, "0");
		}

		for (int j = str2.length() - 1; j >= 0; j--) {
			
			int temp = (str1[i] - 48) * (str2[j] - 48) + carrier;
			if (temp > 9) {
				std::div_t digit = std::div(temp, 10);
				temp = ((str1[i] - 48) * (str2[j] - 48) + carrier) % 10;
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
		singleResults[1] = StringCalc::add(singleResults[0], singleResults[1]);

		std::vector<std::string>::iterator it;
		it = singleResults.begin();
		singleResults.erase(it);
	}
	
	std::string result = singleResults.at(0);
	return result;
}

std::string StringCalc::div(std::string str1, std::string str2) {
	return "";
}

std::string StringCalc::max(std::string str1, std::string str2) {
	
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
