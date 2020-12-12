// Copyright (c) 2020 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include <iostream>
#include <string>
#include <regex>

namespace StringCalc {

	bool isZero(std::string string);

	namespace Decimal {

		// Addition
		std::string add(std::string addend1, std::string addend2);

		// Sutraction
		std::string sub(std::string minuend, std::string subtrahend);

		// Multiplication
		std::string mult(std::string factor1, std::string factor2);

		// Division (without remainder)
		std::string div(std::string dividend, std::string divisor);

		// Exponentiation
		std::string pow(std::string base, std::string exponent);

		// Factorial
		std::string fact(std::string num);

		// Return string with higher value
		// If both strings are the same, the function will return an empty string
		std::string max(std::string str1, std::string str2);

		bool isDecimal(std::string string);

	}

	namespace Binary {

		// Addition
		std::string add_b(std::string addend1, std::string addend2);

		// Sutraction
		std::string sub_b(std::string minuend, std::string subtrahend);

		// Multiplication
		std::string mult_b(std::string factor1, std::string factor2);

		// Division (without remainder)
		std::string div_b(std::string dividend, std::string divisor);

		// Return string with higher value
		// If both strings are the same, the function will return an empty string
		std::string max_b(std::string str1, std::string str2);

		bool isBinary(std::string string);

	}

}
