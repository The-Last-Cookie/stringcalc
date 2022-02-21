// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include <iostream>

typedef unsigned long long uint64;
typedef long long int64;

namespace StringCalc {
	namespace Helper {
		std::string intToString(int num);

		int charToInt(char c);

		// Return string with fewer value
		// If both strings are the same, return an empty string
		// Both numbers need to be in the same base
		std::string min(std::string str1, std::string str2);

		// Return string with higher value
		// If both strings are the same, return an empty string
		// Both numbers need to be in the same base
		std::string max(std::string str1, std::string str2);

		std::string h_add(unsigned int base, std::string addend1, std::string addend2);

		std::string h_sub(unsigned int base, std::string minuend, std::string subtrahend);

		std::string h_mult(unsigned int base, std::string factor1, std::string factor2);

		std::string h_div(unsigned int base, std::string dividend, std::string divisor);

		std::string h_mod(unsigned int base, std::string dividend, std::string divisor);

		std::string h_pow(unsigned int base, std::string baseExp, std::string exponent);

		std::string h_fact(unsigned int base, std::string num);
	}
}
