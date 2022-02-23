// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include <iostream>

#include "stringcalc.h"

// This file is for demonstration purposes

int main() {

	std::cout << "5 + 6 = " << StringCalc::add(10, "5", "6") << "\n";
	std::cout << "12 - 7 = " << StringCalc::sub(10, "12", "7") << "\n";
	std::cout << "8 * 11 = " << StringCalc::mult(10, "8", "11") << "\n";
	std::cout << "10 / 5 = " << StringCalc::div(10, "10", "5") << "\n";
	std::cout << "8 % 3 = " << StringCalc::mod(10, "8", "3") << "\n";
	std::cout << "2 ^ 8 = " << StringCalc::pow(10, "2", "8") << "\n";
	std::cout << "20! = " << StringCalc::fact(10, "20") << "\n\n";

	std::cout << "101 + 1001 = " << StringCalc::add(2, "101", "1001") << "\n";
	std::cout << "1101 - 1011 = " << StringCalc::sub(2, "1101", "1011") << "\n";
	std::cout << "10110 * 111 = " << StringCalc::mult(2, "10110", "111") << "\n";
	std::cout << "10110 / 111 = " << StringCalc::div(2, "10110", "111") << "\n\n";

	std::cout << "10 + 90 = " << StringCalc::add(16, "10", "90") << "\n";
	std::cout << "52 - 3 = " << StringCalc::sub(16, "52", "3") << "\n";
	std::cout << "4F2 * 200 = " << StringCalc::mult(16, "4F2", "200") << "\n";
	std::cout << "5B / 3 = " << StringCalc::div(16, "5B", "3") << "\n\n";

	StringCalc::Converter conv;
	conv.parse("1679615", 10);
	std::cout << "1679615 Base 10 in Base 16 is: " << conv.convertTo(16);

	return 0;
}
