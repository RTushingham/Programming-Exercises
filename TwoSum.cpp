#include <algorithm>
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
std::vector<int> twoSum( std::vector<int>& nums, int target ) {

    std::vector<int> old;

    for(int Index=0;Index<nums.size();Index++){

        old.push_back(nums[Index]);
    }

    std::sort(nums.begin(), nums.end());

    int UpperIndex = nums.size()-1;
    int LowerIndex = 0;

    while( (nums[UpperIndex]+nums[LowerIndex])!=target && LowerIndex<UpperIndex){

        if(nums.at(UpperIndex)+nums.at(LowerIndex) > target ){
            UpperIndex--;
        }
        if(nums.at(UpperIndex)+nums.at(LowerIndex) < target ){
            LowerIndex++;
        }
    }

    std::vector<int> Answer;
    Answer.reserve(2);

    int Index=0;
    for(Index=0; (old[Index]!=nums[LowerIndex] && old[Index]!=nums[UpperIndex]) && Index<old.size();Index++){
    }
    int indexone = Index;

    for(Index=Index+1; (old[Index]!=nums[LowerIndex] && old[Index]!=nums[UpperIndex]) && Index<old.size();Index++){
    }
    int indextwo = Index;

    Answer.push_back( (indexone<indextwo) ? indexone : indextwo );
    Answer.push_back( (indexone<indextwo) ? indextwo : indexone );

    return Answer;
}
};


#include "gtest/gtest.h"

TEST( TwoSumTests, OriginalTests )
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