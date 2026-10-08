
#include <algorithm>
#include <vector>

// EXPLANATION:
// Find the subset of mutually non-adjacent elements of nums which sum to the maximum value.


// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// "SolutionFaster" exists to make this code similar to a valid solution on Leetcode 
class SolutionFaster {
public:
// O(n) complexity, O(n) memory - but faster
int rob(vector<int>& nums) {
    int MaxIndex = nums.size();
    if(MaxIndex == 1)
        return nums[0];
    
    vector<int> ExcludingPrevious(MaxIndex), IncludingPrevious(MaxIndex);
    IncludingPrevious[1] = nums[1];
    ExcludingPrevious[1] = nums[0];
    
    for(int Index = 2; Index < MaxIndex; Index++)
    {
        ExcludingPrevious[Index] = std::max(ExcludingPrevious[Index-1], IncludingPrevious[Index-1]);
        IncludingPrevious[Index] = ExcludingPrevious[Index-1] + nums[Index];
    }
    
    return std::max(ExcludingPrevious[MaxIndex-1], IncludingPrevious[MaxIndex-1]);
}
};


// "SolutionLessMemory" exists to make this code similar to a valid solution on Leetcode 
class SolutionLessMemory {
public:
// O(n) complexity, O(1) memory - but slower
int rob(vector<int>& nums) {
	int MaxIndex = nums.size();
    if(MaxIndex == 1)
        return nums[0];
    
    int ExcludingPrevious = nums[0], IncludingPrevious = nums[1], temp;
    
    for(int Index = 2; Index < MaxIndex; Index++)
    {
        temp = ExcludingPrevious + nums[Index];
        
        ExcludingPrevious = std::max(ExcludingPrevious, IncludingPrevious);
        IncludingPrevious = temp;
    }
    
    return std::max(ExcludingPrevious, IncludingPrevious);
}
};


#include "gtest/gtest.h"

namespace
{
    using AllSolutions = testing::Types<
		SolutionFaster,
        SolutionLessMemory
	>;

    template <typename T>
    class HouseRobberTests : public testing::Test {};

    TYPED_TEST_SUITE( HouseRobberTests, AllSolutions );
}

TYPED_TEST( HouseRobberTests, FromLeetcode )
{
    TypeParam solution{};

    vector<int> data{};
    int expected{};

    data = { 1,2,3,1 };
    expected = 4;
    EXPECT_EQ( solution.rob( data ), expected );

    data = { 2,7,9,3,1 };
    expected = 12;
    EXPECT_EQ( solution.rob( data ), expected );
}
