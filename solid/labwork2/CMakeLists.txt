cmake_minimum_required(VERSION 3.10)
project(BigIntProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/lib)
set(BIGINT_SOURCES
    lib/bigint_arithmetic.cpp
    lib/bigint_parser.cpp
    lib/bigint_formatter.cpp
    lib/bigint_io.cpp
)
set(BIGINT_HEADERS
    lib/uint2022.h
    lib/bigint_arithmetic.h
    lib/bigint_parser.h
    lib/bigint_formatter.h
    lib/bigint_io.cpp
    lib/interfaces/iadder.h
    lib/interfaces/isubtractor.h
    lib/interfaces/imultiplier.h
    lib/interfaces/idivider.h
    lib/interfaces/iequality_comparer.h
    lib/interfaces/icomparer.h
    lib/interfaces/ibigint_parser.h
    lib/interfaces/ibigint_formatter.h
)

add_library(bigint STATIC
    ${BIGINT_SOURCES}
    ${BIGINT_HEADERS}
)

add_executable(example
    bin/main.cpp
)

target_link_libraries(example PRIVATE bigint)
