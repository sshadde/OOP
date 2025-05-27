#pragma once
#include "../uint2022.h"

class IComparer {
public:
    virtual ~IComparer() = default;
    virtual bool lt(const uint2022_t& a, const uint2022_t& b) = 0;
};
