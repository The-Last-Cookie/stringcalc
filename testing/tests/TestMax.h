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

    TEST_CASE("return max(01, 00)") {
        CHECK(StringCalc::Helper::max("01", "00") == "01");
    }

    TEST_CASE("return max(00, 01)") {
        CHECK(StringCalc::Helper::max("00", "01") == "01");
    }

    TEST_CASE("return max(0, 0)") {
        CHECK(StringCalc::Helper::max("0", "0") == "");
    }

    TEST_CASE("return max(00, 00)") {
        CHECK(StringCalc::Helper::max("00", "00") == "");
    }

    TEST_CASE("return max(005, 00006)") {
        CHECK(StringCalc::Helper::max("005", "00006") == "00006");
    }

    TEST_CASE("return max(005, 2)") {
        CHECK(StringCalc::Helper::max("005", "2") == "005");
    }

    TEST_CASE("return empty on empty input") {
        CHECK(StringCalc::Helper::max("", "") == "");
    }

    TEST_CASE("return empty for the same letter in different letter cases") {
        CHECK(StringCalc::Helper::max("A", "a") == "");
    }
}
