
#include <vector>
using namespace std;

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
vector<int> productExceptSelf(vector<int>& nums) {
    
    vector<int> BottomTriangle;
    BottomTriangle.resize(nums.size());
    
    int runningproduct=1;
    for(int Index=nums.size()-1;Index>0;Index--){
        BottomTriangle[Index] = runningproduct;
        runningproduct*=nums[Index];
    }
    BottomTriangle[0] = runningproduct;
    
    int PreviousProduct=1;
    runningproduct=1;
    
    for(int Index=0;Index<nums.size();Index++){
        runningproduct *= nums[Index];
        
        nums[Index] = BottomTriangle[Index]*PreviousProduct;
        
        PreviousProduct = runningproduct;
    }
    
    return nums;
}
};


#include "gtest/gtest.h"

TEST( ProductExceptSelfTests, Tests )
{
    Solution solution{};
    std::vector<int> data;
	std::vector<int> expected;

    data = { 1,2,3,4 };
	expected = { 24, 12, 8, 6 };
    EXPECT_EQ( solution.productExceptSelf(data), expected );

    data = { -1,1,0,-3,3 };
	expected = { 0, 0, 9, 0, 0 };
    EXPECT_EQ( solution.productExceptSelf(data), expected );
}
