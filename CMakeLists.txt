cmake_minimum_required(VERSION 4.1)
project(cppAlgo)

set(CMAKE_CXX_STANDARD 20)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(include)

# Find all solution files
file(GLOB_RECURSE SRC_FILES "src/*/*.cpp")

# Create a single library for all solutions
add_library(solutions ${SRC_FILES})

# Find all test files
file(GLOB_RECURSE TEST_FILES "tests/*/*.cpp")

# Create one test executable
add_executable(all_tests ${TEST_FILES})

target_link_libraries(all_tests solutions gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(all_tests)
