// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include "doctest.h"
#include "random.h"

TEST_SUITE("test converter") {
	StringCalc::Converter conv;

	TEST_CASE("Convert 0") {
		conv.parse("0", 10);
		CHECK(conv.convertTo(16) == "0");
	}
	
	TEST_CASE("Convert 1") {
		conv.parse("1", 10);
		CHECK(conv.convertTo(16) == "1");
	}
	
	TEST_CASE("Convert A Base 16 to Base 10") {
		conv.parse("A", 16);
		CHECK(conv.convertTo(10) == "10");
	}
	
	TEST_CASE("Convert ZZZ Base 36 to Base 10") {
		conv.parse("ZZZ", 36);
		CHECK(conv.convertTo(10) == "46655");
	}

	TEST_CASE("Convert 1679615 Base 10 to Base 16") {
		conv.parse("1679615", 10);
		CHECK(conv.convertTo(16) == "19A0FF");
	}

	TEST_CASE("Convert 1679615 Base 10 to Base 16") {
		conv.parse("1679615", 10);
		CHECK(conv.convertTo(16) == "19A0FF");
	}

	TEST_CASE("Convert 1679615 Base 10 to Base 16") {
		conv.parse("1679615", 10);
		CHECK(conv.convertTo(16) == "19A0FF");
	}

	TEST_CASE("Convert 1679615 Base 10 to Base 16") {
		conv.parse("1679615", 10);
		CHECK(conv.convertTo(16) == "19A0FF");
	}
}
