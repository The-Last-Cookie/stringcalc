// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include "doctest.h"
#include "random.h"

TEST_SUITE("test subtraction") {
	// TODO: activate tests as soon as negativity is implemented
	/*TEST_CASE("return 0 - 0") {
		CHECK(StringCalc::sub(10, "0", "0") == "0");
		CHECK(StringCalc::sub(10, "00", "0000") == "0");
	}*/

	TEST_CASE("return 1 - 0") {
		CHECK(StringCalc::sub(10, "1", "0") == "1");
	}

	/*TEST_CASE("return 999 - 999") {
		CHECK(StringCalc::sub(10, "999", "999") == "0");
	}*/

	TEST_CASE("return 100F - G") {
		CHECK(StringCalc::sub(36, "100F", "G") == "ZZZ");
	}

	TEST_CASE("return 15E - U") {
		CHECK(StringCalc::sub(31, "15E", "U") == "14F");
	}

	/*TEST_CASE("subtract two random numbers"
		* doctest::description("fails if random numbers overflow")
		* doctest::may_fail(true)) {

		// To reduce the probability of overflow, use half the value of INT_MAX
		int rand1 = Random::randInt(0, INT_MAX / 2);
		int rand2 = Random::randInt(0, INT_MAX / 2);

		INFO("The numbers are ", rand1, " and ", rand2);

		std::string num1 = std::to_string(rand1);
		std::string num2 = std::to_string(rand2);
		std::string result = std::to_string(rand1 + rand2);

		CHECK(StringCalc::sub(10, num1, num2) == result);
	}*/
}
