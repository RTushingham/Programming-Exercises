#include <optional>
#include <utility>
#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<std::pair<int,unsigned>> previous_subsequence_ending_values{};

		unsigned max{ 0 };

		for( const auto num : nums )
		{
			std::optional<unsigned> l{};

			for( const auto prev_seq : previous_subsequence_ending_values )
			{
				if( prev_seq.first < num )
				{
					l = l.has_value() && l.value() > prev_seq.second?
						l.value() :
						prev_seq.second;
				}
			}
			
			const auto new_len{ l.value_or(0)+1 };
			max = std::max( max, new_len );

			previous_subsequence_ending_values.push_back( { num, new_len } );
		}

		return max;
    }
};


#include "gtest/gtest.h"

TEST( LongestIncreasingSubsequenceVector, Tests )
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
