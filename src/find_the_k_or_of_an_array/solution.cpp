#include "find_the_k_or_of_an_array/solution.h"

namespace find_the_k_or_of_an_array
{
int Solution::findKOr(std::vector<int>& nums, int& k)
{
    int result = 0;
    int numsLen = nums.size();
    bool done = false;
    int iteration = 0;

    while (!done && iteration<32)
    {
        int sum = 0;
        int maxCur = 1 << iteration;
        bool shouldContinue = false;

        int j = 0;
        while (j < numsLen && sum < k)
        {
            int cur = nums[j];
            if (cur >= maxCur)
            {
                shouldContinue = true;
                if ((cur & maxCur) != 0)
                {
                    sum += 1;
                }
            }
            j++;
        }

        if (sum >= k)
        {
            result = result | maxCur;
        }
        done = !shouldContinue;
        iteration++;
    }


    return result;
}
}