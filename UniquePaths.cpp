
#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

long long get_binomial_coefficient( int n, int k )
{
    const int min_terms_count{ std::min( k,n-k ) };

    long long runningproduct=1;
    
    for(int Multiplier=n-min_terms_count+1, divisor=1; Multiplier<n+1; Multiplier++, divisor++){
        runningproduct *= Multiplier;
		runningproduct /= divisor;
    }

	return runningproduct;
}

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
int uniquePaths( int m, int n ) {
    return (int)get_binomial_coefficient( m+n-2, m-1 );
}
};


#include "gtest/gtest.h"

TEST( UniquePathsTests, Tests )
{
    Solution solution{};
	vector<int> data;
	int expected;


	data = { 1,1 };
	expected = 1;
    EXPECT_EQ( solution.uniquePaths(data.at(0),data.at(1)), expected );
	
	data = { 3,7 };
	expected = 28;
    EXPECT_EQ( solution.uniquePaths(data.at(0),data.at(1)), expected );	
	
	data = { 3,2 };
	expected = 3;
    EXPECT_EQ( solution.uniquePaths(data.at(0),data.at(1)), expected );	
	
	data = { 10,10 };
	expected = 48620;
    EXPECT_EQ( solution.uniquePaths(data.at(0),data.at(1)), expected );	
	
	data = { 51,9 };
	expected = 1916797311;
    EXPECT_EQ( solution.uniquePaths(data.at(0),data.at(1)), expected );
}

