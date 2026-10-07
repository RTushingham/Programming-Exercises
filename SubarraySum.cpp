
#include <vector>
#include <unordered_map>
using namespace std;

// Return the number of contigous non-empty subarrays which sum to k

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
int subarraySum(vector<int>& nums, int k) {
    
    	std::unordered_map<int,std::vector<int>> Visits;
        
        int RunningSum=0;
        Visits[0].push_back(0);
        
        for(int Index=0;Index<nums.size();Index++){
            RunningSum += nums.at(Index);
            Visits[RunningSum].push_back(Index+1);
        }
        
        int ReturnValue=0;
        if(k!=0){
        	for( const auto& key : Visits ) {
	            if(Visits.count(key.first+k)!=0){
	            	std::vector<int> LargerGroup = Visits[key.first+k];
	            	std::vector<int> SmallerGroup = Visits[key.first];
	            	int IndexForLargerGroup = 0;
					int IndexForSmallerGroup = 0;
	            	while(IndexForLargerGroup<LargerGroup.size() && IndexForSmallerGroup<SmallerGroup.size()){
						bool NextLargerGroupWasLater = LargerGroup[IndexForLargerGroup]>SmallerGroup[IndexForSmallerGroup];
						
						ReturnValue += NextLargerGroupWasLater ? LargerGroup.size()-IndexForLargerGroup : 0;
						IndexForLargerGroup += NextLargerGroupWasLater ? 0 : 1;
						IndexForSmallerGroup += NextLargerGroupWasLater ? 1 : 0;
					}
	            }
    	    }
		}else{
			for( const auto& key : Visits ) {
				int value = Visits[key.first].size();
				
                ReturnValue += value%2==1? ((value-1)/2)*value : (value/2)*(value-1);
            }
		}
		
        return ReturnValue;
}
};


#include "gtest/gtest.h"

TEST( SubarraySumTests, Tests )
{
    Solution solution{};
    std::vector<int> data;
	int k;
	int expected;

    data = { 1,1,1 };
	k = 2;
	expected = 2;
    EXPECT_EQ( solution.subarraySum(data,k), expected );

    data = { 1,2,3 };
	k = 3;
	expected = 2;
    EXPECT_EQ( solution.subarraySum(data,k), expected );

    data = { 1,-1,1,-1 };
	k = 0;
	expected = 4;
    EXPECT_EQ( solution.subarraySum(data,k), expected );

    data = { -1,-1,1 };
	k = 1;
	expected = 1;
    EXPECT_EQ( solution.subarraySum(data,k), expected );

    data = { 1,2,3 };
	k = -1;
	expected = 0;
    EXPECT_EQ( solution.subarraySum(data,k), expected );

    data = { 2,-2,2,-2 };
	k = 2;
	expected = 3;
    EXPECT_EQ( solution.subarraySum(data,k), expected );

    data = { 1,-1,2,-2,2,-2 };
	k = 2;
	expected = 5;
    EXPECT_EQ( solution.subarraySum(data,k), expected );

    data = { 1,-1,2,-2,2,-1,1,-2 };
	k = 2;
	expected = 8;
    EXPECT_EQ( solution.subarraySum(data,k), expected );
}
