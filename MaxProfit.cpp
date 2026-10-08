
#include <algorithm>
#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
int maxProfit(vector<int>& prices) {
    int Max{ 0 };
    int bottom{ prices.front() };
    int top{ prices.front() };
    
    for(const auto& price : prices)
    {
        // The following line is is equivalent to  "if( price<bottom ){ top = price; }"
        top = price<bottom ? price : top;

        bottom = std::min( price, bottom );
        top = std::max( price, top );
        
        Max = std::max( top-bottom, Max );        
    }
    
    return Max;
}
};


#include "gtest/gtest.h"

TEST( MaxProfitTests, Tests )
{
    Solution solution{};
    
    vector<int> nums;
    int expected;
    
    nums = { 7,1,5,3,6,4 };
    expected = 5;
    EXPECT_EQ( solution.maxProfit( nums ), expected );
    
    nums = { 7,6,4,3,1 };
    expected = 0;
    EXPECT_EQ( solution.maxProfit( nums ), expected );
}
