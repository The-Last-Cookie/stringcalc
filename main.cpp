#include <iostream>

#include "stringcalc.h"

// This file is for demonstration purposes

int main() {
	
	std::cout << "5 + 6 = " << StringCalc::add("5", "6") << "\n";

	std::cout << StringCalc::sub("0", "0") << "\n";

	std::cout << StringCalc::mult("0", "0") << "\n";

	std::cout << StringCalc::div("0", "0") << "\n";
	
	return 0;
}
