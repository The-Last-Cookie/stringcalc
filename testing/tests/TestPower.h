// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include "doctest.h"
#include "random.h"

TEST_SUITE("test power") {
	TEST_CASE("return 0 ^ 0") {
		CHECK(StringCalc::pow(10, "0", "0") == "");
		CHECK(StringCalc::pow(10, "00", "0000") == "");
	}

	TEST_CASE("return 1 ^ 0") {
		CHECK(StringCalc::pow(10, "1", "0") == "1");
	}

	TEST_CASE("return 5 ^ 7") {
		CHECK(StringCalc::pow(10, "5", "7") == "78125");
	}

	TEST_CASE("return 10 ^ 5") {
		CHECK(StringCalc::pow(10, "10", "5") == "100000");
	}
}
