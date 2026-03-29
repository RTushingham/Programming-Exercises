#include <unordered_map>
#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// You are given an integer array and a target integer.
//   Find the indexes of two distinct entries of the array which sum to the target.
// Assume:
//   the array contains a unique solution
//   2 <= nums.length <= 10**4
//   -(10**5) <= nums[i] <= 10**5
//   -(10**5) <= target <= 10**5

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
std::vector<int> twoSum( std::vector<int>& nums, int target ) 
{
    std::unordered_map<int, std::size_t> previousValues;

    std::size_t Index=0;
    for( Index=0; Index<nums.size(); Index++ )
    {
        if( previousValues.count( target - nums[Index] ) != 0 )
        {
            break;
        }
        else if( previousValues.count( nums[Index] ) == 0 )
        {
            previousValues.insert( { nums[Index], Index } );
        }
    }

    std::vector<int> Answer;
    Answer.resize(2);
    Answer = { (int)previousValues[target - nums[Index]], (int)Index };
    return Answer;
}
};


#include "gtest/gtest.h"

TEST( TwoSumTests, Tests )
{
    Solution solution{};
    std::vector<int> data;
    int k;

    data = { 2,7,11,15 };
    k = 9;
    EXPECT_EQ( solution.twoSum(data,k), std::vector<int>({0,1}) );

    data = { 3,2,4 };
    k = 6;
    EXPECT_EQ( solution.twoSum(data,k), std::vector<int>({1,2}) );

    data = { 3,3 };
    k = 6;
    EXPECT_EQ( solution.twoSum(data,k), std::vector<int>({0,1}) );
}