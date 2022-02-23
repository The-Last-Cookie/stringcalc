// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include "../doctest.h"

TEST_SUITE("test max function") {
    TEST_CASE("return max(10, 0)") {
        CHECK(StringCalc::Helper::max("10", "0") == "10");
    }

    TEST_CASE("return max(1, 0)") {
        CHECK(StringCalc::Helper::max("1", "0") == "1");
    }

    TEST_CASE("return max(0, 1)") {
        CHECK(StringCalc::Helper::max("0", "1") == "1");
    }

    TEST_CASE("return max(0, 0)") {
        CHECK(StringCalc::Helper::max("0", "0") == "");
    }

    TEST_CASE("return empty on empty input") {
        CHECK(StringCalc::Helper::max("", "") == "");
    }

    TEST_CASE("return empty for the same letter in different letter cases") {
        CHECK(StringCalc::Helper::max("A", "a") == "");
    }
}
