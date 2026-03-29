#include <vector>
#include <array>
#include <algorithm>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        
        std::vector<std::array<int, 2>> structre;
        structre.reserve(2*nums.size()+1);
        
        for(int Index = 0; Index<2*nums.size()+1; Index++){
            structre[Index][0] = 0;
            structre[Index][1] = 0;
        }
        
        int RunningSum=nums.size();
        
        for(int Index=0; Index<nums.size(); Index++){
            
            RunningSum += 2*nums[Index]-1;
            
            if( (structre[RunningSum][0]==0) && (RunningSum!=nums.size()) ){
                structre[RunningSum][0] = Index+1;
            }
            structre[RunningSum][1] = Index+1;
            
        }
        
        int MaxLength=0;
        {
            int Index=nums.size();
            if(structre[Index][1]-structre[Index][0] > MaxLength){
                MaxLength = structre[Index][1]-structre[Index][0];
            }
        }
        
        for(int Index=nums.size()+1; Index<2*nums.size()+1 && structre[Index][1]!=0; Index++){
            
            if(structre[Index][1]-structre[Index][0] > MaxLength){
                MaxLength = structre[Index][1]-structre[Index][0];
            }
        }
        for(int Index=nums.size()-1; Index>=0 && structre[Index][1]!=0; Index--){
            
            if(structre[Index][1]-structre[Index][0] > MaxLength){
                MaxLength = structre[Index][1]-structre[Index][0];
            }
        }
        return MaxLength;
    }
};


#include "gtest/gtest.h"

TEST( FindMaxLength, GeneralTests )
{
    Solution solution{};
    std::vector<int> data; 
    
    data = { 0,1 };
    EXPECT_EQ(solution.findMaxLength(data), 2);
    data = { 0,1,0 };
    EXPECT_EQ(solution.findMaxLength(data), 2);
    data = { 0,1,1 };
    EXPECT_EQ(solution.findMaxLength(data), 2);
    data = { 0,1,1,0,1,1,1,0 };
    EXPECT_EQ(solution.findMaxLength(data), 4);
    data = { 0,1,0,0,0,0 };
    EXPECT_EQ(solution.findMaxLength(data), 2);
    data = { 1,1,1,1,1,1,1 };
    EXPECT_EQ(solution.findMaxLength(data), 0);
    data = { 1,1,1,1,1,1,1,1 };
    EXPECT_EQ(solution.findMaxLength(data), 0);
    data = { 0,0,0,0,0,0,0 };
    EXPECT_EQ(solution.findMaxLength(data), 0);
    data = { 0,0,0,0,0,0,0,0 };
    EXPECT_EQ(solution.findMaxLength(data), 0);
    data = { 0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1 };
    EXPECT_EQ(solution.findMaxLength(data), 6);
    data = { 1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1 };
    EXPECT_EQ(solution.findMaxLength(data), 6);
}