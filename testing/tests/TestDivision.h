// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include "doctest.h"
#include "random.h"

TEST_SUITE("test division") {
	TEST_CASE("return empty for division through 0") {
		CHECK(StringCalc::div(10, "0", "0") == "");
		CHECK(StringCalc::div(10, "00", "0000") == "");
	}

	TEST_CASE("return 0 / 1") {
		CHECK(StringCalc::div(10, "0", "1") == "0");
	}

	TEST_CASE("return 999 / 999") {
		CHECK(StringCalc::div(10, "999", "999") == "1");
	}

	TEST_CASE("return 000010 / 005") {
		CHECK(StringCalc::div(10, "000010", "005") == "2");
	}

	TEST_CASE("return 010 / 0005") {
		CHECK(StringCalc::div(10, "010", "0005") == "2");
	}

	TEST_CASE("return 0010 / 0005") {
		CHECK(StringCalc::div(10, "0010", "0005") == "2");
	}

	TEST_CASE("return ZZA / P") {
		CHECK(StringCalc::div(36, "ZZA", "P") == "1FT");
	}

	TEST_CASE("return 15E / U") {
		CHECK(StringCalc::div(31, "15E", "U") == "16");
	}

	TEST_CASE("return 312 / 2") {
		CHECK(StringCalc::div(4, "312", "2") == "123");
	}

	TEST_CASE("return 223 / 4") {
		CHECK(StringCalc::div(6, "223", "4") == "33");
	}

	TEST_CASE("return 104 / 3") {
		CHECK(StringCalc::div(5, "104", "3") == "14");
	}
}
