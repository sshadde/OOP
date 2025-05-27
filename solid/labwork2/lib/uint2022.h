#pragma once
#include <cinttypes>

struct uint2022_t {
    static const int SIZE = 64;
    uint32_t data[SIZE];

    uint2022_t() {
        for (int i = 0; i < SIZE; ++i)
            data[i] = 0;
    }
};
