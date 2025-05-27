#include "bigint_parser.h"

uint2022_t BigIntParser::from_uint(uint32_t i) {
    uint2022_t r;
    r.data[0] = i;
    return r;
}

uint2022_t BigIntParser::from_string(const std::string& str) {
    uint2022_t r;
    for (char ch : str) {
        uint64_t carry = 0;
        for (int i = 0; i < uint2022_t::SIZE; ++i) {
            uint64_t t = (uint64_t)r.data[i] * 10 + carry;
            r.data[i] = uint32_t(t);
            carry = t >> 32;
        }

        uint32_t d = ch - '0';
        carry = d;

        for (int i = 0; i < uint2022_t::SIZE && carry; ++i) {
            uint64_t t = (uint64_t)r.data[i] + carry;
            r.data[i] = uint32_t(t);
            carry = t >> 32;
        }
    }
    return r;
}
