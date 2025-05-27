#pragma once
#include "../uint2022.h"
#include <string>
#include <ostream>

class IBigIntFormatter {
public:
    virtual ~IBigIntFormatter() = default;

    virtual std::string to_string(const uint2022_t& v) = 0;
    virtual std::ostream& print(std::ostream& os, const uint2022_t& v) = 0;
};
