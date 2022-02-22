// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "helper.h"
#include "converter.h"
#include "number.h"

namespace StringCalc {

	// Addition
	std::string add(unsigned int base, std::string addend1, std::string addend2);

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
