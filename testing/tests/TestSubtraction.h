// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include "doctest.h"
#include "random.h"

TEST_SUITE("test subtraction") {
	TEST_CASE("return 0 - 0") {
		CHECK(StringCalc::sub(10, "0", "0") == "0");
		CHECK(StringCalc::sub(10, "00", "0000") == "0");
	}

	TEST_CASE("return 1 - 0") {
		CHECK(StringCalc::sub(10, "1", "0") == "1");
	}

	TEST_CASE("return 999 - 999") {
		CHECK(StringCalc::sub(10, "999", "999") == "0");
	}

	TEST_CASE("return 100F - G") {
		CHECK(StringCalc::sub(36, "100F", "G") == "ZZZ");
	}

	TEST_CASE("return 15E - U") {
		CHECK(StringCalc::sub(31, "15E", "U") == "14F");
	}

	TEST_CASE("return 5 - 5") {
		CHECK(StringCalc::sub(10, "5", "5") == "0");
	}

	TEST_CASE("return 5 - (-5)") {
		CHECK(StringCalc::sub(10, "5", "-5") == "10");
	}

	TEST_CASE("return 5 - (-4)") {
		CHECK(StringCalc::sub(10, "5", "-4") == "9");
	}

	TEST_CASE("return 5 - (-6)") {
		CHECK(StringCalc::sub(10, "5", "-6") == "11");
	}

	TEST_CASE("return (-5) - 5") {
		CHECK(StringCalc::sub(10, "-5", "5") == "-10");
	}

	TEST_CASE("return (-5) - 4") {
		CHECK(StringCalc::sub(10, "-5", "4") == "-9");
	}

	TEST_CASE("return (-5) - 6") {
		CHECK(StringCalc::sub(10, "-5", "6") == "-11");
	}

	TEST_CASE("return (-5) - (-5)") {
		CHECK(StringCalc::sub(10, "-5", "-5") == "0");
	}

	TEST_CASE("return (-5) - (-6)") {
		CHECK(StringCalc::sub(10, "-5", "-6") == "1");
	}

	TEST_CASE("return (-12) - (-25)") {
		CHECK(StringCalc::sub(10, "-12", "-25") == "13");
	}

	TEST_CASE("return (-20) - (-4)") {
		CHECK(StringCalc::sub(10, "-20", "-4") == "-16");
	}
}
