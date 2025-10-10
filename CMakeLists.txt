cmake_minimum_required(VERSION 3.10)
project(ScientificCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# Source files (exclude main.cpp for tests)
file(GLOB CALC_SOURCES "src/*.cpp")
list(REMOVE_ITEM CALC_SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

# Build the main calculator
add_executable(calculator src/main.cpp ${CALC_SOURCES})

# ===== Optional Testing Section =====
option(BUILD_TESTS "Build unit tests" ON)

if(BUILD_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})
    file(GLOB TEST_SOURCES "tests/*.cpp")
    add_executable(runTests ${TEST_SOURCES} ${CALC_SOURCES})
    target_link_libraries(runTests GTest::gtest_main pthread)
    add_test(NAME CalculatorTests COMMAND runTests)
endif()
