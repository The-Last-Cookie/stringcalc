// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include "../doctest.h"

TEST_SUITE("test min function") {
    TEST_CASE("return min(10, 0)") {
        CHECK(StringCalc::Helper::min("10", "0") == "0");
    }

    TEST_CASE("return min(1, 0)") {
        CHECK(StringCalc::Helper::min("1", "0") == "0");
    }

    TEST_CASE("return min(0, 1)") {
        CHECK(StringCalc::Helper::min("0", "1") == "0");
    }

    TEST_CASE("return min(0, 0)") {
        CHECK(StringCalc::Helper::min("0", "0") == "");
    }

    TEST_CASE("return empty on empty input") {
        CHECK(StringCalc::Helper::min("", "") == "");
    }

    TEST_CASE("return empty for the same letter in different letter cases") {
        CHECK(StringCalc::Helper::min("A", "a") == "");
    }
}
