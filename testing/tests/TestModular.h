// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include "doctest.h"
#include "random.h"

TEST_SUITE("test modular arithmetic") {
	TEST_CASE("return 0 % 2") {
		CHECK(StringCalc::mod(10, "0", "2") == "0");
		CHECK(StringCalc::mod(10, "00", "2") == "0");
	}

	TEST_CASE("return 9 % 5") {
		CHECK(StringCalc::mod(10, "9", "5") == "4");
	}

	TEST_CASE("return 998 % 999") {
		CHECK(StringCalc::mod(10, "998", "999") == "998");
	}
}
