#pragma once
#include "../uint2022.h"

class IEqualityComparer {
public:
    virtual ~IEqualityComparer() = default;

    virtual bool eq(const uint2022_t& a, const uint2022_t& b) = 0;
    virtual bool neq(const uint2022_t& a, const uint2022_t& b) = 0;
};
