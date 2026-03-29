#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
int maxProduct(vector<int>& nums) {
    
    int runningproduct=1;
    bool SeenANegative=0;
    int RunningproductAfterNegative=1;
    int Max=nums[0];
    
    for(int Index=0;Index<nums.size();Index++){
    	runningproduct *= nums[Index];
    	Max = Max>runningproduct ? Max : runningproduct;
    	
    	if(SeenANegative){
    		RunningproductAfterNegative *= nums[Index];
    		Max = Max>RunningproductAfterNegative ? Max : RunningproductAfterNegative;
		}
		
		if(!SeenANegative && nums[Index]<0){
			SeenANegative = 1;
		}
		if(nums[Index]==0){
			runningproduct=1;
			SeenANegative=0;
			RunningproductAfterNegative=1;
		}
	}
	return Max;
}
};


#include "gtest/gtest.h"

TEST( MaxProduct, Tests )
{
	Solution solution{};
	
	std::vector<int> data; 
	int result;
	int expected;
	
	
	data = { 2,3,-2,4 };
	expected = 6;
	EXPECT_EQ( solution.maxProduct(data), expected );
	
	data = { -2,0,-1 };
	expected = 0;
	EXPECT_EQ( solution.maxProduct(data), expected );
	
	data = { 2,3,-2,4,1,-1,-3,2,3 };
	expected = 72;
	EXPECT_EQ( solution.maxProduct(data), expected );
	
	data = { -2,-1,-3 };
	expected = 3;
	EXPECT_EQ( solution.maxProduct(data), expected );
	
	data = { 2,3,-2,4,-1,-1,-3,2,3 };
	expected = 864;
	EXPECT_EQ( solution.maxProduct(data), expected );
	
	data = { -2,-1 };
	expected = 2;
	EXPECT_EQ( solution.maxProduct(data), expected );
	
	data = { 2,1,3 };
	expected = 6;
	EXPECT_EQ( solution.maxProduct(data), expected );
	
	data = { 0,2,1,3,0 };
	expected = 6;
	EXPECT_EQ( solution.maxProduct(data), expected );
	
	data = { 0,0 };
	expected = 0;
	EXPECT_EQ( solution.maxProduct(data), expected );
	
	data = { 2,-3,2,4 };
	expected = 8;
	EXPECT_EQ( solution.maxProduct(data), expected );
	
	data = { -3 };
	expected = -3;
	EXPECT_EQ( solution.maxProduct(data), expected );
	
	data = { 0,-3,0 };
	expected = 0;
	EXPECT_EQ( solution.maxProduct(data), expected );
	
	data = { -3,2 };
	expected = 2;
	EXPECT_EQ( solution.maxProduct(data), expected );
	
	data = { 3,-3 };
	expected = 3;
	EXPECT_EQ( solution.maxProduct(data), expected );
	
	data = { 2,3,0,2,3,-2,4,1,-1,-3,2,3 };
	expected = 72;
	EXPECT_EQ( solution.maxProduct(data), expected );
}
