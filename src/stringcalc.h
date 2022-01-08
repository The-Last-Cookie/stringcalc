// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "converter.h"

typedef unsigned long long uint64;
typedef long long int64;

namespace StringCalc {

	bool isZero(std::string string);

	std::string removeLeadingZeros(std::string str);

	std::string intToString(int num);

	int charToInt(char c);

	bool isInBase(std::string str, unsigned int base);

	// Return string with fewer value
	// If both strings are the same, return an empty string
	std::string min(std::string str1, std::string str2);

	// Return string with higher value
	// If both strings are the same, return an empty string
	std::string max(std::string str1, std::string str2);

	// Addition
	std::string add(std::string addend1, std::string addend2);

	// Sutraction
	std::string sub(std::string minuend, std::string subtrahend);

	// Multiplication
	std::string mult(std::string factor1, std::string factor2);

	// Division (without remainder)
	std::string div(std::string dividend, std::string divisor);

	// Modulo
	std::string mod(std::string dividend, std::string divisor);

	// Exponentiation
	std::string pow(std::string base, std::string exponent);

	// Factorial
	std::string fact(std::string num);
}
