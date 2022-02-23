#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../src/stringcalc.h"

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

TEST_SUITE("test charToInt") {
    TEST_CASE("return 0 as integer") {
        CHECK(StringCalc::Helper::charToInt('0') == 0);
    }

    TEST_CASE("return 9 as integer") {
        CHECK(StringCalc::Helper::charToInt('9') == 9);
    }

    /*TEST_CASE("return 10 as A") {
        CHECK(StringCalc::Helper::intToString(10) == "A");
    }

    TEST_CASE("return 35 as Z") {
        CHECK(StringCalc::Helper::intToString(35) == "Z");
    }*/

    TEST_CASE("return -1 for invalid input") {
        CHECK(StringCalc::Helper::charToInt(' ') == -1);
        CHECK(StringCalc::Helper::charToInt(-1) == -1);
    }
}
