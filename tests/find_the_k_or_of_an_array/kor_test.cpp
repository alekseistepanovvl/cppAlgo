#include <gtest/gtest.h>
#include "find_the_k_or_of_an_array/solution.h"

using namespace find_the_k_or_of_an_array;

class KOrTest : public ::testing::TestWithParam<std::tuple<std::vector<int>, int, int>> {};

TEST_P(KOrTest, HandlesKOr)
{
    auto [nums, k, expected] = GetParam();

    Solution solution;
    EXPECT_EQ(solution.findKOr(nums, k), expected);
}

INSTANTIATE_TEST_SUITE_P(
    KOrTests,
    KOrTest,
    ::testing::Values(
        std::make_tuple(std::vector<int> {7,12,9,8,9,15},4,9),
        std::make_tuple(std::vector<int> {2,12,1,11,4,5},6,0),
        std::make_tuple(std::vector<int> {10,8,5,9,11,6,8},1,15),
        std::make_tuple(std::vector<int> {2}, 1, 2)
    )
);