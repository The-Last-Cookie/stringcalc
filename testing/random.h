// Copyright (c) 2022 The-Last-Cookie
// Licensed under the MIT Licence.
// See the LICENCE file for more information.

#pragma once

#include <chrono>
#include <random>

namespace Random {
    int randInt(int min, int max) {
        // taken from
        // https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c

        std::random_device rd;
        // seed value is designed specifically to make initialization
        // parameters of std::mt19937 (instance of std::mersenne_twister_engine<>)
        // different across executions of application
        std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count() +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count());

        std::mt19937 gen(seed);

        std::mt19937::result_type n;
        // reject readings that would make n%6 non-uniformly distributed
        while ((n = gen()) > std::mt19937::max() -
            (std::mt19937::max() - 5) % 6)
        {
            /* bad value retrieved so get next one */
        }

        return n % (max)+min;
    }
}
