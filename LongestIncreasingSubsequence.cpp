#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
    int lengthOfLIS( vector<int>& nums ) {
        std::vector<int> pile;

        for( int num : nums )
		{
            auto it = std::lower_bound( pile.begin(), pile.end(), num );

			if( it == pile.end() )
			{
                pile.push_back( num );
            }
			else
			{
				*it = num;
            }
        }
		
        return pile.size();
    }
};


#include "gtest/gtest.h"

TEST( LongestIncreasingSubsequence, Tests )
{
    Solution solution{};
	
	std::vector<int> data;
	int expected;
	
	
	data = { 10,9,2,5,3,7,101,18 };
	expected = 4;
	EXPECT_EQ( solution.lengthOfLIS(data), expected );
	
	data = { 0,1,0,3,2,3 };
	expected = 4;
	EXPECT_EQ( solution.lengthOfLIS(data), expected );
	
	data = { 7,7,7,7,7,7,7 };
	expected = 1;
	EXPECT_EQ( solution.lengthOfLIS(data), expected );
	
	data = { 1 };
	expected = 1;
	EXPECT_EQ( solution.lengthOfLIS(data), expected );
	
	data = { 1,2 };
	expected = 2;
	EXPECT_EQ( solution.lengthOfLIS(data), expected );

	data = { 3,5,6,2,5,4,19,5,6,7,12 };
	expected = 6;
	EXPECT_EQ( solution.lengthOfLIS(data), expected );
}
