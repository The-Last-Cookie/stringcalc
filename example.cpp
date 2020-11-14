// Copyright (c) 2020 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#include <iostream>

#include "stringcalc.h"

// This file is for demonstration purposes

int main() {
	
	std::cout << "5 + 6 = " << StringCalc::add("5", "6") << "\n";

	std::cout << "12 - 7 = " << StringCalc::sub("12", "7") << "\n";

	std::cout << "8 * 11 = " << StringCalc::mult("8", "11") << "\n";

	std::cout << "10 / 5 = " << StringCalc::div("10", "5") << "\n";
	
	return 0;
}
