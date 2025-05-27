#pragma once
#include "uint2022.h"
#include "interfaces/iadder.h"
#include "interfaces/isubtractor.h"
#include "interfaces/imultiplier.h"
#include "interfaces/idivider.h"
#include "interfaces/iequality_comparer.h"
#include "interfaces/icomparer.h"

class BigIntArithmetic
    : public IAdder
    , public ISubtractor
    , public IMultiplier
    , public IDivider
    , public IEqualityComparer
    , public IComparer
{
public:
    uint2022_t add(const uint2022_t& a, const uint2022_t& b) override;
    uint2022_t sub(const uint2022_t& a, const uint2022_t& b) override;
    uint2022_t mul(const uint2022_t& a, const uint2022_t& b) override;
    uint2022_t div(const uint2022_t& a, const uint2022_t& b) override;

    bool eq(const uint2022_t& a, const uint2022_t& b) override;
    bool neq(const uint2022_t& a, const uint2022_t& b) override;
    bool lt(const uint2022_t& a, const uint2022_t& b) override;
};
