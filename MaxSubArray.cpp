#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
int maxSubArray(vector<int>& nums) {
	
	int CurrentMax = nums[0];
	int RunningSum=0;
	for(int Index=0;Index<nums.size();Index++){
		RunningSum += nums[Index];
		CurrentMax = (RunningSum>CurrentMax) ? RunningSum : CurrentMax;
		RunningSum = (0>RunningSum) ? 0 : RunningSum;
	}
	return CurrentMax;
}
};


#include "gtest/gtest.h"

TEST( MaxSubArray, Tests )
{
	Solution solution;
	
	std::vector<int> data; 
	int result;
	int expected;
	
	
	data = { -2,1,-3,4,-1,2,1,-5,4 };
	expected = 6;
	EXPECT_EQ( solution.maxSubArray(data), expected );
	
	data = { 1 };
	expected = 1;
	EXPECT_EQ( solution.maxSubArray(data), expected );
	
	data = { 5,4,-1,7,8 };
	expected = 23;
	EXPECT_EQ( solution.maxSubArray(data), expected );
	
	data = { 3142, 5021, 1717, -2276, 2219, 8105, -5916, -1155, 4258, 7791, 589, 5858, 4499, -51, 2430, -9618, -7491, -7944, 5372, -5309, -6930, -8973, -2572, 5546, 2245, -4933, 8952, 804, 6795, -4742, -6657, 3742, 6159, -3819, -7105, -8863, -6855, 3697, -7623, -8898, 4451, -3520, -2152, -1318, 8540, 711, -9438, 1380, -1505, 2374, 1959, 9343, -9346, -3329, -1906, 5117, -4173, 1150, 7950, -434, 5331, 5783, 5492, -5810, -3297, -3992, -6603, 6826, -6834, -8733, 4382, 832, -417, 659, -7440, 7480, 221, -8304, -2511, 1187, -917, 942, 501, 8451, 7744, -1910, 1780, 5829, 8003, -2316, -16, 9830, 5280, 8417, 9017, 4203, -2779, 3246, -8611, 4198, 309, -9446, 9333, 9812, 4652, 6310, -9569, 1545, 5230, -2721, 8151, -1378, -4779, -7020, -7950, 1670, 1056, 4346, -6960, 725, 8466, 919, 5202, -7150, 4175, -3335, 5508, -3999 };
	expected = 85685;
	EXPECT_EQ( solution.maxSubArray(data), expected );
}
