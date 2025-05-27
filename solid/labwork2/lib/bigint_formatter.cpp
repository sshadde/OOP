#include "bigint_formatter.h"
#include "bigint_arithmetic.h"
#include <algorithm>

std::string BigIntFormatter::to_string(const uint2022_t& value) {
    BigIntArithmetic arith;
    uint2022_t temp = value;
    uint2022_t zero;
    std::string s;

    while (!arith.eq(temp, zero)) {
        uint64_t rem = 0;
        for (int i = uint2022_t::SIZE - 1; i >= 0; --i) {
            uint64_t cur = (rem << 32) | temp.data[i];
            temp.data[i] = uint32_t(cur / 10);
            rem = cur % 10;
        }
        s.push_back(char('0' + rem));
    }

    if (s.empty()) s = "0";
    else std::reverse(s.begin(), s.end());

    return s;
}

std::ostream& BigIntFormatter::print(std::ostream& os, const uint2022_t& value) {
    os << to_string(value);
    return os;
}
