// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include "doctest.h"
#include "random.h"

TEST_SUITE("test addition") {
	TEST_CASE("return 0 * 0") {
		CHECK(StringCalc::mult(10, "0", "0") == "0");
		CHECK(StringCalc::mult(10, "00", "0000") == "0");
	}

	TEST_CASE("return 1 * 0") {
		CHECK(StringCalc::mult(10, "1", "0") == "0");
	}

	TEST_CASE("return 999 * 999") {
		CHECK(StringCalc::mult(10, "999", "999") == "998001");
	}

	TEST_CASE("return ZZA * P") {
		CHECK(StringCalc::mult(36, "ZZA", "P") == "OZHY");
	}

	TEST_CASE("return 15E * U") {
		CHECK(StringCalc::mult(31, "15E", "U") == "148H");
	}
}
