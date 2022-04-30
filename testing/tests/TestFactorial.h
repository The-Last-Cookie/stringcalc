// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include "doctest.h"
#include "random.h"

TEST_SUITE("test factorial") {
	TEST_CASE("return 0") {
		CHECK(StringCalc::fact(10, "0") == "1");
		CHECK(StringCalc::fact(10, "00") == "1");
	}

	TEST_CASE("return 1") {
		CHECK(StringCalc::fact(10, "1") == "1");
	}
	
	TEST_CASE("return 5") {
		CHECK(StringCalc::fact(10, "5") == "120");
	}
	
	TEST_CASE("return 100 Base 2") {
		CHECK(StringCalc::fact(2, "100") == "11000");
	}
}
