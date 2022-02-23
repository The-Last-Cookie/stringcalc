// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include "../doctest.h"

TEST_SUITE("test intToString") {
    TEST_CASE("return 0 as string") {
        CHECK(StringCalc::Helper::intToString(0) == "0");
    }

    TEST_CASE("return 9 as string") {
        CHECK(StringCalc::Helper::intToString(9) == "9");
    }

    TEST_CASE("return 10 as A") {
        CHECK(StringCalc::Helper::intToString(10) == "A");
    }

    TEST_CASE("return 35 as Z") {
        CHECK(StringCalc::Helper::intToString(35) == "Z");
    }

    TEST_CASE("return empty string for invalid input") {
        CHECK(StringCalc::Helper::intToString(36) == "");
        CHECK(StringCalc::Helper::intToString(-1) == "");
    }
}
