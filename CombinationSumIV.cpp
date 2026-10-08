
#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
int combinationSum4(vector<int>& nums, int target) 
{    
    vector<unsigned> CountOfSetsWhichSumTo( target+1, 0 );
    CountOfSetsWhichSumTo[ 0 ] = 1;
    // First value is set to 1 is a sentinal value.
    //   - If an entry in  nums == temp_target  then the number of possible ways to create a set which sums to  temp_target  should be incremented by 1.
    //       - This can be done by setting  CountOfSetsWhichSumTo.at( 0 )  to be  1.
    
    for( int temp_target{ 1 }; temp_target <= target; temp_target++ )
    {
        for( auto num : nums )
        {
            if( num <= temp_target )
            {
                CountOfSetsWhichSumTo[ temp_target ] += CountOfSetsWhichSumTo[ temp_target - num ];
            }
        }
    }
    
    return CountOfSetsWhichSumTo[ target ];
}
};


#include "gtest/gtest.h"

TEST( CombinationSumIVTests, Tests )
{
    Solution solution{};
    
    vector<int> nums;
    int target;
    int expected;
    
    nums = { 1,2,3 };
    target = 4;
    expected = 7;
    EXPECT_EQ( solution.combinationSum4( nums, target ), expected );
    
    nums = { 9 };
    target = 3;
    expected = 0;
    EXPECT_EQ( solution.combinationSum4( nums, target ), expected );
}
