
#include <cstdint>

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ReturnValue=0;
        while(n)
        {
            n &= (n-1);
            ReturnValue++;
        }
        return ReturnValue;
    }
};


#include "gtest/gtest.h"

TEST( HammingWeightTests, FromLeetcode )
{
    Solution solution{};

    uint32_t data{};
    int expected{};

    data = 11;
    expected = 3;
    EXPECT_EQ( solution.hammingWeight( data ), expected );

    data = 128;
    expected = 1;
    EXPECT_EQ( solution.hammingWeight( data ), expected );

    data = 2147483645;
    expected = 30;
    EXPECT_EQ( solution.hammingWeight( data ), expected );
}
