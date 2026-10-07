#include <algorithm>
#include <functional>
#include <map>
#include <optional>
#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// "SolutionLISMap" exists to make this code identical to a valid solution on Leetcode 
class SolutionLISMap {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::map<int,unsigned,std::greater<int>> previous_subsequence_ending_values{};

		unsigned max{ 0 };

		for( const auto num : nums )
		{
			std::optional<unsigned> l{};

			auto lower{ previous_subsequence_ending_values.upper_bound( num ) };
				
			while( lower != previous_subsequence_ending_values.end() )
			{
				l = l.has_value() && l.value() > lower->second?
					l.value() :
					lower->second;

				lower++;
			}
			
			const auto new_len{ l.value_or(0)+1 };
			max = std::max( max, new_len );

			previous_subsequence_ending_values[ num ] = new_len;
		}

		return max;
    }
};


#include "gtest/gtest.h"

TEST( LongestIncreasingSubsequenceOrlogn, Tests )
{
    SolutionLISMap solution{};
	
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
