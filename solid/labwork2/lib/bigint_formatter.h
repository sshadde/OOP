#pragma once
#include "uint2022.h"
#include "interfaces/ibigint_formatter.h"
#include <string>
#include <ostream>

class BigIntFormatter : public IBigIntFormatter {
public:
    std::string to_string(const uint2022_t& value) override;
    std::ostream& print(std::ostream& os, const uint2022_t& value) override;
};
