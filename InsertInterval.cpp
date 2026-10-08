
#include <algorithm>
#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    
    vector<vector<int>> ReturnValue, Bigger;
    int nIntevalSize{ (int)intervals.size() }, nFirstIndex{ 0 }, nFinalIndex{ nIntevalSize }, a{ newInterval[0] }, b{ newInterval[1] };
    
    ReturnValue.reserve(nIntevalSize);
    
    
    for(int Index=0; Index<intervals.size(); Index++)
    {
        if(intervals[Index][1] < newInterval[0])
        {
            ReturnValue.push_back(intervals[Index]);
        }
        else if(intervals[Index][0] > newInterval[1])
        {
            Bigger.push_back(intervals[Index]);
        }
        else
        {
            a = std::min(intervals[Index][0], a);
            b = std::max(intervals[Index][1], b);
        }
    }
    vector<int> toAdd;
    toAdd.resize(2);
    toAdd[0]=a;
    toAdd[1]=b;
    ReturnValue.push_back(toAdd);
    
    ReturnValue.insert(ReturnValue.end(), Bigger.begin(), Bigger.end());
    
    return ReturnValue;
}
};


#include "gtest/gtest.h"

TEST( InsertIntervalTests, FromLeetcode )
{
    Solution solution{};

    vector<vector<int>> data{};
    vector<int> new_interval{};
    vector<vector<int>> expected{};

    data = {{1,3},{6,9}};
    new_interval = {2,5};
    expected = {{1,5},{6,9}};
    EXPECT_EQ( solution.insert( data, new_interval ), expected );

    data = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    new_interval = {4,8};
    expected = {{1,2},{3,10},{12,16}};
    EXPECT_EQ( solution.insert( data, new_interval ), expected );
}
