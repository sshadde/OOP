#pragma once
#include "../uint2022.h"
#include <string>

class IBigIntParser {
public:
    virtual ~IBigIntParser() = default;

    virtual uint2022_t from_uint(uint32_t i) = 0;
    virtual uint2022_t from_string(const std::string& s) = 0;
};
