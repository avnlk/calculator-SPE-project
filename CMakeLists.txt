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

# Enable testing
enable_testing()

# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test sources
file(GLOB TEST_SOURCES "tests/*.cpp")

# Build test executable (without main.cpp)
add_executable(runTests ${TEST_SOURCES} ${CALC_SOURCES})
target_link_libraries(runTests GTest::gtest_main pthread)

# Register tests with CTest
add_test(NAME CalculatorTests COMMAND runTests)

