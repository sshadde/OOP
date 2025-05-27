#pragma once
#include "../uint2022.h"

class IAdder {
public:
    virtual ~IAdder() = default;
    virtual uint2022_t add(const uint2022_t& a, const uint2022_t& b) = 0;
};
