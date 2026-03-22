#include <gtest/gtest.h>
#include "two_sum/solution.h"

using namespace sum_problem;

class SumTest : public ::testing::TestWithParam<std::tuple<int, int, int>> {};

TEST_P(SumTest, HandlesSum)
{
    auto [a, b, expected] = GetParam();

    Solution solution;
    EXPECT_EQ(solution.sum(a, b), expected);
}

INSTANTIATE_TEST_SUITE_P(
    SumTests,
    SumTest,
    ::testing::Values(
        std::make_tuple(2,3,5),
        std::make_tuple(0,0,0),
        std::make_tuple(1,-2,-1)
    )
);