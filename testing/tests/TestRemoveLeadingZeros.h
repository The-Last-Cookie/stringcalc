// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include "../doctest.h"

TEST_SUITE("test removeLeadingZeros function") {
    TEST_CASE("return 0") {
        CHECK(StringCalc::Helper::removeLeadingZeros("0") == "0");
        CHECK(StringCalc::Helper::removeLeadingZeros("00") == "0");
    }

    TEST_CASE("return empty on empty input") {
        CHECK(StringCalc::Helper::removeLeadingZeros("") == "");
    }
}
