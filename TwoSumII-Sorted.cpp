#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// "SolutionTwoSumSorted" class is here to make this code analogous to a valid solution on Leetcode 
class SolutionTwoSumSorted {
public:
vector<int> twoSum( std::vector<int>& nums, int target ) {
    size_t first = 0, second = nums.size()-1;
    
    while( first<second )
    {
        int sum = nums[first] + nums[second];
        if( sum < target )
        {
            first++;
        }
        else if( sum > target )
        {
            second--;
        }
        else
        {
            break;
        }
    }
    return{ (int)first+1, (int)second+1 };
}
};


#include "gtest/gtest.h"

TEST( TwoSumSortedTests, Tests )
{
    SolutionTwoSumSorted solution{};
    std::vector<int> data;
    int k;

    data = { 2,7,11,15 };
    k = 9;
    EXPECT_EQ( solution.twoSum(data,k), std::vector<int>({1,2}) );
    k = 13;
    EXPECT_EQ( solution.twoSum(data,k), std::vector<int>({1,3}) );
    k = 18;
    EXPECT_EQ( solution.twoSum(data,k), std::vector<int>({2,3}) );
    k = 22;
    EXPECT_EQ( solution.twoSum(data,k), std::vector<int>({2,4}) );
    k = 26;
    EXPECT_EQ( solution.twoSum(data,k), std::vector<int>({3,4}) );

    data = { 2,3,4 };
    k = 6;
    EXPECT_EQ( solution.twoSum(data,k), std::vector<int>({1,3}) );

    data = { 3,3 };
    k = 6;
    EXPECT_EQ( solution.twoSum(data,k), std::vector<int>({1,2}) );
}

