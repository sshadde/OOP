#include "bigint_io.h"
#include "bigint_formatter.h"

std::ostream& operator<<(std::ostream& stream, const uint2022_t& value) {
    BigIntFormatter fmt;
    return fmt.print(stream, value);
}
