#include <algorithm>
#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// Given a vector of integers both positive and negative.
//   Find all tripples of elements in that vector which sum to zero.
//   Return all index triplets of elements of the vector which sum to 0

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
    
    vector<vector<int>> returnValue;
    
    std::sort(nums.begin(), nums.end());
    
    for(int first=0; first+1 < nums.size(); first++)
    {
        int second = first+1, third = nums.size()-1;
        
        while(second < third)
        {
            int sum = nums[second] + nums[third];
            if(sum < -nums[first])
            {
                second++;
            }
            else if(sum > -nums[first])
            {
                third--;
            }
            else
            {
                vector<int> toPushBack = {nums[first], nums[second], nums[third]};
                returnValue.push_back(toPushBack);
                
                while(second < third && nums[second] == toPushBack[1])
                {
                    second++;
                }
                while(second < third && nums[third] == toPushBack[2])
                {
                    third--;
                }
            }
        }
        
        while(first+1 < nums.size() && nums[first] == nums[first+1])
        {
            first++;
        }
    }
    
    return returnValue;
}
};


#include "gtest/gtest.h"

TEST( ThreeSum, FromLeetcode )
{
    Solution solution{};
    vector<int> nums;
    vector<vector<int>> answer;
    
    nums = vector<int>{ -1,0,1,2,-1,-4 };
    answer = vector<vector<int>>{ {-1,-1,2},{-1,0,1} };
    EXPECT_EQ( solution.threeSum( nums ), answer );
    
    nums = vector<int>{ 0,1,1 };
    answer = vector<vector<int>>{};
    EXPECT_EQ( solution.threeSum( nums ), answer );
    
    nums = vector<int>{ 0,0,0 };
    answer = vector<vector<int>>{ {0,0,0} };
    EXPECT_EQ( solution.threeSum( nums ), answer );
}
