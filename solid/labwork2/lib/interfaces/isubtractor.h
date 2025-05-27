#pragma once
#include "../uint2022.h"

class ISubtractor {
public:
    virtual ~ISubtractor() = default;
    virtual uint2022_t sub(const uint2022_t& a, const uint2022_t& b) = 0;
};
