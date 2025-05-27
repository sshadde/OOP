#pragma once
#include "../uint2022.h"

class IDivider {
public:
    virtual ~IDivider() = default;
    virtual uint2022_t div(const uint2022_t& a, const uint2022_t& b) = 0;
};
