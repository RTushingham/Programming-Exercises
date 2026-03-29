#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// Given a rotated sorted list find the minimum element.

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
int findMin(vector<int>& nums) {
    
    int FirstIndexOfSection = 0;
    int min = nums[FirstIndexOfSection];
    int LengthOfSection = nums.size();
    
    while(LengthOfSection>1){
        int CentreIndex = FirstIndexOfSection + LengthOfSection/2;
        if(nums[FirstIndexOfSection] > nums[CentreIndex]){
            LengthOfSection = CentreIndex - FirstIndexOfSection;
            min = nums[CentreIndex];
        }else{
            LengthOfSection = LengthOfSection + FirstIndexOfSection - CentreIndex;
            FirstIndexOfSection = CentreIndex;
        }
    }
	return min;
}
};


#include "gtest/gtest.h"

TEST( findMin, BasicTests )
{
    Solution solution{};
	vector<int> data;
	int expected;
	
	data = { 3,4,5,1,2 };
	expected = 1;
	EXPECT_EQ(solution.findMin(data), expected);
	
	
	data = { 2,3,4,5,1 };
	expected = 1;
	EXPECT_EQ(solution.findMin(data), expected);
	
	
	data = { 4,5,6,7,0,1,2 };
	expected = 0;
	EXPECT_EQ(solution.findMin(data), expected);
	
	
	data = { 11,13,15,17 };
	expected = 11;
	EXPECT_EQ(solution.findMin(data), expected);
	
	
	data = { 1,2,3 };
	expected = 1;
	EXPECT_EQ(solution.findMin(data), expected);
	
	data = { 1,2,3,4,5 };
	expected = 1;
	EXPECT_EQ(solution.findMin(data), expected);
	
	data = { 1,2,3,4,5,6,7 };
	expected = 1;
	EXPECT_EQ(solution.findMin(data), expected);
	
	data = { 1,2,3,4,5,6 };
	expected = 1;
	EXPECT_EQ(solution.findMin(data), expected);
}