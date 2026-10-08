
#include <algorithm>
#include <vector>

// EXPLANATION:
// Find the subset of mutually non-adjacent elements of nums which sum to the maximum value.
//   - Any subset which contains both the first and last entry must be excluded.


// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
int rob(vector<int>& nums) {
    int MaxIncludingPreviousIncZero = 0, MaxExcludingPreviousIncZero = 0, dummyIncZero;
    int MaxIncludingPreviousExZero = 0, MaxExcludingPreviousExZero = 0, dummyExZero;
    int LoopMax = nums.size()-1;
    
    dummyIncZero = MaxExcludingPreviousIncZero + nums[0];
    MaxExcludingPreviousIncZero = std::max(MaxIncludingPreviousIncZero, MaxExcludingPreviousIncZero);
    MaxIncludingPreviousIncZero = dummyIncZero;
    
    for(int Index=1; Index<LoopMax; Index++)
    {
        dummyIncZero = MaxExcludingPreviousIncZero + nums[Index];
        MaxExcludingPreviousIncZero = std::max(MaxIncludingPreviousIncZero, MaxExcludingPreviousIncZero);
        MaxIncludingPreviousIncZero = dummyIncZero;
        
        dummyExZero = MaxExcludingPreviousExZero + nums[Index];
        MaxExcludingPreviousExZero = std::max(MaxIncludingPreviousExZero, MaxExcludingPreviousExZero);
        MaxIncludingPreviousExZero = dummyExZero;
    }
    if(LoopMax>0)
    {
        dummyExZero = MaxExcludingPreviousExZero + nums[LoopMax];
        MaxExcludingPreviousExZero = std::max(MaxIncludingPreviousExZero, MaxExcludingPreviousExZero);
        MaxIncludingPreviousExZero = dummyExZero;
    }
    
    int a = std::max(MaxIncludingPreviousIncZero,MaxExcludingPreviousIncZero), b = std::max(MaxIncludingPreviousExZero,MaxExcludingPreviousExZero);
    return std::max(a,b);
}
};


#include "gtest/gtest.h"

TEST( HouseRobberIITests, FromLeetcode )
{
    Solution solution{};

    vector<int> data{};
    int expected{};

    data = { 2,3,2 };
    expected = 3;
    EXPECT_EQ( solution.rob( data ), expected );

    data = { 1,2,3,1 };
    expected = 4;
    EXPECT_EQ( solution.rob( data ), expected );

    data = { 1,2,3 };
    expected = 3;
    EXPECT_EQ( solution.rob( data ), expected );
}
