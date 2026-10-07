
#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// returns the result of xoring all numbers from 0 to end_value together
int getRunningXor( const size_t& end_value )
{
	switch (end_value % 4) {
		case 0:
			return end_value;
		case 1:
			return 1;
		case 2:
			return (end_value + 1);
		case 3:
			return 0;
	}
}

// "SolutionMissingNumber" exists to make this code identical to a valid solution on Leetcode 
class SolutionMissingNumber {
public:
int missingNumber(vector<int> &A){
	int running_xor{ getRunningXor( A.size() ) };

	for( const auto num : A )
	{
		running_xor ^= num;
	}
	
	return running_xor;
}
};


#include "gtest/gtest.h"

TEST(MissingNumberTests, RunningXor)
{
	auto manually_created_r_xor = []( const size_t& end_value ){
		int running_xor{};

		for( int index{ 0 }; index < end_value+1; index++ )
		{
			running_xor ^= index;
		}

		return running_xor;
	};

	size_t test_count{ 0 };
	for( size_t index{ 0 }; index<160; index++ )
	{
		EXPECT_EQ( getRunningXor(index), manually_created_r_xor(index) );
		test_count++;
	}
	
    EXPECT_EQ( test_count, 160 );
}

TEST(MissingNumberTests, SampleTests)
{
    SolutionMissingNumber solution{};
	std::vector<int> data;
	int expected;
	
    
	data = { 3,0,1 };
	expected = 2;
    EXPECT_EQ( solution.missingNumber(data), expected );
	
	data = { 0,1 };
	expected = 2;
    EXPECT_EQ( solution.missingNumber(data), expected );
	
	data = { 9,6,4,2,3,5,7,0,1 };
	expected = 8;
    EXPECT_EQ( solution.missingNumber(data), expected );
	
	data = { 1 };
	expected = 0;
    EXPECT_EQ( solution.missingNumber(data), expected );
	
	data = { 1,2 };
	expected = 0;
    EXPECT_EQ( solution.missingNumber(data), expected );
}
