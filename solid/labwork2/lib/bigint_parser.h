#pragma once
#include "uint2022.h"
#include "interfaces/ibigint_parser.h"
#include <string>

class BigIntParser : public IBigIntParser {
public:
    uint2022_t from_uint(uint32_t i) override;
    uint2022_t from_string(const std::string& str) override;
};
