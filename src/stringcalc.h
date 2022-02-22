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
	std::string sub(unsigned int base, std::string minuend, std::string subtrahend);

	// Multiplication
	std::string mult(unsigned int base, std::string factor1, std::string factor2);

	// Division (without remainder)
	std::string div(unsigned int base, std::string dividend, std::string divisor);

	// Modulo
	std::string mod(unsigned int base, std::string dividend, std::string divisor);

	// Exponentiation
	std::string pow(unsigned int base, std::string baseExp, std::string exponent);

	// Factorial
	std::string fact(unsigned int base, std::string num);
}
