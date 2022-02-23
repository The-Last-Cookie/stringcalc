// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include "../doctest.h"

TEST_SUITE("test number class") {
    TEST_CASE("return false for empty input") {
        StringCalc::Number n = StringCalc::Number(2, "");
        CHECK(!n.isValid());
    }

    TEST_CASE("return false for invalid base") {
        StringCalc::Number n = StringCalc::Number(1, "0");
        CHECK(!n.isValid());

        n = StringCalc::Number(0, "0");
        CHECK(!n.isValid());

        n = StringCalc::Number(2, "0");
        CHECK(n.isValid());

        n = StringCalc::Number(36, "0");
        CHECK(n.isValid());

        n = StringCalc::Number(37, "0");
        CHECK(!n.isValid());
    }

    TEST_CASE("return false for invalid number") {
        StringCalc::Number n = StringCalc::Number(2, "4(");
        CHECK(!n.isValid());
    }

    TEST_CASE("add zeros") {
        StringCalc::Number n = StringCalc::Number(2, "0");
        n.addZeros(4);
        CHECK(n.value == "00000");
    }
}
