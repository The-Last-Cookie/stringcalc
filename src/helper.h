// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include <iostream>

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

		std::string p_add(std::string addend1, std::string addend2);

		std::string p_sub(std::string minuend, std::string subtrahend);

		std::string p_mult(std::string factor1, std::string factor2);

		std::string p_div(std::string dividend, std::string divisor);

		std::string p_mod(std::string dividend, std::string divisor);

		std::string p_pow(std::string base, std::string exponent);

		std::string p_fact(std::string num);
	}
}
