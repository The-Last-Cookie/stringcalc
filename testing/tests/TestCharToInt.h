// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include "doctest.h"

TEST_SUITE("test charToInt") {
    TEST_CASE("return 0 as integer") {
        CHECK(StringCalc::Helper::charToInt('0') == 0);
    }

    TEST_CASE("return 9 as integer") {
        CHECK(StringCalc::Helper::charToInt('9') == 9);
    }

    TEST_CASE("return A as 10") {
        CHECK(StringCalc::Helper::charToInt('A') == 10);
        CHECK(StringCalc::Helper::charToInt('a') == 10);
    }

    TEST_CASE("return Z as 35") {
        CHECK(StringCalc::Helper::charToInt('Z') == 35);
        CHECK(StringCalc::Helper::charToInt('z') == 35);
    }

    TEST_CASE("return -1 for invalid input") {
        CHECK(StringCalc::Helper::charToInt(' ') == -1);
        CHECK(StringCalc::Helper::charToInt(-1) == -1);
    }
}
