#pragma once
#include "../uint2022.h"

class IMultiplier {
public:
    virtual ~IMultiplier() = default;
    virtual uint2022_t mul(const uint2022_t& a, const uint2022_t& b) = 0;
};
