#include <vector>
#include <unordered_map>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// Finds the count of all elements of nums which have a pair in nums such that the absolute difference between them is k.

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
int FindPairs(vector<int>& nums, int k) 
{
    int pair_count = 0;
    // We only count the lower number of the pair, so tracking is unique to the pair.
    std::unordered_map<int, bool> counted_numbers;
    
    counted_numbers.reserve(nums.size());
    
    if(k!=0)
    {
        for(const auto num : nums)
        {
            if( 0 == counted_numbers.count(num) )
            {
                counted_numbers.insert({num, false});
            }
            
            if( 0 < counted_numbers.count(num+k) && false == counted_numbers[num] )
            {
                pair_count++;
                counted_numbers[num] = true;
            }

            if( 0 < counted_numbers.count(num-k) && false == counted_numbers[num-k])
            {
                pair_count++;
                counted_numbers[num-k] = true;
            }
        }
    }
    else
    {
        for(const auto num : nums)
        {
            if( 0 == counted_numbers.count(num) )
            {
                counted_numbers.insert({num, false});
            }
            else if( counted_numbers[num]==false )
            {
                pair_count++;
                counted_numbers[num]=true;
            }
        }
    }

    return pair_count;
}
};


#include "gtest/gtest.h"

TEST( FindPairs, GeneralTests )
{
    Solution solution{};
	std::vector<int> data; 
	int k;
	
	data = { 0,1 };
	k = 1;
    EXPECT_EQ(solution.FindPairs(data,k), 1);
	
	data = { 0,1,2 };
	k = 1;
    EXPECT_EQ(solution.FindPairs(data,k), 2);
	
	data = { 2,1,0 };
	k = 1;
    EXPECT_EQ(solution.FindPairs(data,k), 2);
	
	data = { 3,1,4,1,5 };
	k = 2;
	EXPECT_EQ(solution.FindPairs(data,k), 2);
	
	data = { 1,2,3,4,5 };
	k = 1;
	EXPECT_EQ(solution.FindPairs(data,k), 4);
	
	data = { 3,1,4,1,5 };
	k = 0;
    EXPECT_EQ(solution.FindPairs(data,k), 1);
	
	data = { -1,-2,-3 };
	k = 1;
	EXPECT_EQ(solution.FindPairs(data,k), 2);
	
	data = { 3,2,1 };
	k = 1;
	EXPECT_EQ(solution.FindPairs(data,k), 2);	
}