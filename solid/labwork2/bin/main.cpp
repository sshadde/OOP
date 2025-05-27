#include <iostream>
#include "interfaces/iadder.h"
#include "interfaces/imultiplier.h"
#include "interfaces/ibigint_parser.h"
#include "interfaces/ibigint_formatter.h"
#include "bigint_arithmetic.h"
#include "bigint_parser.h"
#include "bigint_formatter.h"

void demoAdd(IAdder& adder, IBigIntParser& parser, IBigIntFormatter& fmt)
{
    auto a = parser.from_string("12345678901234567890");
    auto b = parser.from_string("98765432109876543210");
    auto c = adder.add(a, b);
    std::cout << "Sum = " << fmt.to_string(c) << "\n";
}

void demoMul(IMultiplier& multiper, IBigIntParser& parser, IBigIntFormatter& fmt)
{
    auto x = parser.from_string("4294967296");
    auto y = parser.from_string("4294967296");
    auto m = multiper.mul(x, y);
    std::cout << "2^32 * 2^32 = " << fmt.to_string(m) << "\n";
}

int main() {
    BigIntParser     parserImpl;
    BigIntArithmetic arithImpl;
    BigIntFormatter  formatterImpl;

    demoAdd(arithImpl, parserImpl, formatterImpl);
    demoMul(arithImpl, parserImpl, formatterImpl);
    return 0;
}

