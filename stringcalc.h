// Copyright (c) 2020 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include <iostream>
#include <string>
#include <regex>

namespace StringCalc {

	// Addition
	std::string add(std::string str1, std::string str2);

	// Sutraction
	std::string sub(std::string str1, std::string str2);

	// Multiplication
	std::string mult(std::string str1, std::string str2);

	// Division (without remainder)
	std::string div(std::string str1, std::string str2);

	// Return string with higher value
	// If both strings are the same, the function will return an empty string
	std::string max(std::string str1, std::string str2);

}
