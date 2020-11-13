#include "stringcalc.h"

std::string StringCalc::add(std::string str1, std::string str2) {
	
	// Input sanitization
	if (!std::regex_match(str1, std::regex("[0-9]+")) || !std::regex_match(str2, std::regex("[0-9]+"))) {
		std::cout << "Error: Strings may only contain numbers!" << "\n";
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
		std::cout << "Error: Strings may only contain numbers!";
		return "";
	}
	else if (str2 == "0") {
		return str1;
	}
	else if (str1 == "0") {
		return "-" + str2;
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
	return "";
}

std::string StringCalc::div(std::string str1, std::string str2) {
	return "";
}
