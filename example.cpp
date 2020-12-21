// Copyright (c) 2020 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include <iostream>

#include "stringcalc.h"

// This file is for demonstration purposes

int main() {
	
	std::cout << "5 + 6 = " << StringCalc::Decimal::add("5", "6") << "\n";
	std::cout << "12 - 7 = " << StringCalc::Decimal::sub("12", "7") << "\n";
	std::cout << "8 * 11 = " << StringCalc::Decimal::mult("8", "11") << "\n";
	std::cout << "10 / 5 = " << StringCalc::Decimal::div("10", "5") << "\n";
	std::cout << "2 ^ 8 = " << StringCalc::Decimal::pow("2", "8") << "\n";
	std::cout << "20! = " << StringCalc::Decimal::fact("20") << "\n\n";

	std::cout << "101 + 1001 = " << StringCalc::Binary::add_b("101", "1001") << "\n";
	std::cout << "1101 - 1011 = " << StringCalc::Binary::sub_b("1101", "1011") << "\n";
	std::cout << "10110 * 111 = " << StringCalc::Binary::mult_b("10110", "111") << "\n";
	std::cout << "10110 / 111 = " << StringCalc::Binary::div_b("10110", "111") << "\n\n";

	std::cout << "10 + 90 = " << StringCalc::Hexadecimal::add_h("10", "90") << "\n";
	std::cout << "52 - 3 = " << StringCalc::Hexadecimal::sub_h("52", "3") << "\n";
	std::cout << "4F2 * 200 = " << StringCalc::Hexadecimal::mult_h("4F2", "200") << "\n";
	std::cout << "5B / 3 = " << StringCalc::Hexadecimal::div_h("5B", "3") << "\n";

	return 0;
}
