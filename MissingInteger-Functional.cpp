#include <functional>
#include <numeric>
#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// Given an array containing n distinct numbers in the range [0, n], return the only number in the range that is missing.
// Assume:
//   n == nums.length
//   0 <= nums[i] <= n
//   all of the elements of nums are distinct

constexpr int running_bit_xor( int n )
{
    return n == 0 ? 0 : n ^ running_bit_xor( n - 1 );
}

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
int missingNumber(const std::vector<int>& nums) {
    return running_bit_xor( nums.size() ) ^ std::accumulate( nums.cbegin(), nums.cend(), 0, std::bit_xor<int>() );
}
};


#include "gtest/gtest.h"

TEST(MissingNumberTests, SampleTests)
{
    Solution solution{};
	std::vector<int> data;
	int expected;
	
    
	data = { 3,0,1 };
	expected = 2;
    EXPECT_EQ( solution.missingNumber(data), expected );
	
	
	data = { 0,1 };
	expected = 2;
    EXPECT_EQ( solution.missingNumber(data), expected );
	
	
	data = { 9,6,4,2,3,5,7,0,1 };
	expected = 8;
    EXPECT_EQ( solution.missingNumber(data), expected );
	
	
	data = { 1 };
	expected = 0;
    EXPECT_EQ( solution.missingNumber(data), expected );
	
	
	data = { 1,2 };
	expected = 0;
    EXPECT_EQ( solution.missingNumber(data), expected );
}