// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include "doctest.h"
#include "random.h"

TEST_SUITE("test addition") {
	TEST_CASE("return 0 + 0") {
		CHECK(StringCalc::add(10, "0", "0") == "0");
		CHECK(StringCalc::add(10, "00", "0000") == "0");
	}

	TEST_CASE("return 1 + 0") {
		CHECK(StringCalc::add(10, "1", "0") == "1");
	}

	TEST_CASE("return 999 + 999") {
		CHECK(StringCalc::add(10, "999", "999") == "1998");
	}

	TEST_CASE("return ZZA + P") {
		CHECK(StringCalc::add(36, "ZZA", "P") == "ZZZ");
	}

	TEST_CASE("return 15E + U") {
		CHECK(StringCalc::add(31, "15E", "U") == "16D");
	}

	TEST_CASE("add two random numbers"
		* doctest::description("fails if random numbers overflow")
		* doctest::may_fail(true)) {

		// To reduce the probability of overflow, use half the value of INT_MAX
		int rand1 = Random::randInt(0, INT_MAX / 2);
		int rand2 = Random::randInt(0, INT_MAX / 2);

		INFO("The numbers are ", rand1, " and ", rand2);

		std::string num1 = std::to_string(rand1);
		std::string num2 = std::to_string(rand2);
		std::string result = std::to_string(rand1 + rand2);

		CHECK(StringCalc::add(10, num1, num2) == result);
	}

	TEST_CASE("return 5 + (-5)") {
		CHECK(StringCalc::add(10, "5", "-5") == "0");
	}

	TEST_CASE("return 5 + (-4)") {
		CHECK(StringCalc::add(10, "5", "-4") == "1");
	}

	TEST_CASE("return 5 + (-6)") {
		CHECK(StringCalc::add(10, "5", "-6") == "-1");
	}

	TEST_CASE("return (-5) + 5") {
		CHECK(StringCalc::add(10, "-5", "5") == "0");
	}

	TEST_CASE("return (-5) + 4") {
		CHECK(StringCalc::add(10, "-5", "4") == "-1");
	}

	TEST_CASE("return (-5) + 6") {
		CHECK(StringCalc::add(10, "-5", "6") == "1");
	}

	TEST_CASE("return (-5) + (-5)") {
		CHECK(StringCalc::add(10, "-5", "-5") == "-10");
	}

	TEST_CASE("return (-5) + (-6)") {
		CHECK(StringCalc::add(10, "-5", "-6") == "-11");
	}
}
