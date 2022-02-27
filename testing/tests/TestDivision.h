// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include "doctest.h"
#include "random.h"

TEST_SUITE("test addition") {
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

	TEST_CASE("return ZZA / P") {
		CHECK(StringCalc::div(36, "ZZA", "P") == "1FT");
	}

	TEST_CASE("return 15E / U") {
		CHECK(StringCalc::div(31, "15E", "U") == "16");
	}
}