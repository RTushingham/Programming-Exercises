#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
int missingNumber(vector<int>& nums) {
    int RunningXor = 0;
    int Reference = nums.size();
    
    for(int Index=0; Index<nums.size(); Index++){
        RunningXor = RunningXor^nums[Index];
        Reference = Reference^Index;
    }
    return RunningXor^Reference;
}
};


#include "gtest/gtest.h"

TEST( MissingNumberRevisited, Tests )
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
