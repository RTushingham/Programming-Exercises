#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

// "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution {
public:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
    int width = matrix[0].size();
    int height = matrix.size();
    
    vector<int> Output;
    int SpiralIndex;
    int ColumnIndex;
    int RowIndex;
    
    for(SpiralIndex=0; SpiralIndex<(std::min(width, height)/2); SpiralIndex++){
        
        RowIndex = SpiralIndex;
        for(ColumnIndex=SpiralIndex; ColumnIndex<width-SpiralIndex; ColumnIndex++){
            Output.push_back(matrix[RowIndex][ColumnIndex]);
        }
        ColumnIndex--;
        
        for(RowIndex++; RowIndex<height-SpiralIndex; RowIndex++){
            Output.push_back(matrix[RowIndex][ColumnIndex]);
        }
        RowIndex--;
        
        for(ColumnIndex--; ColumnIndex>=SpiralIndex; ColumnIndex--){
            Output.push_back(matrix[RowIndex][ColumnIndex]);
        }
        ColumnIndex++;
        
        for(RowIndex--; RowIndex>=SpiralIndex+1; RowIndex--){
            Output.push_back(matrix[RowIndex][ColumnIndex]);
        }
    }
    if(std::min(width, height)%2==1){
        
        RowIndex = SpiralIndex;
        for(ColumnIndex=SpiralIndex; ColumnIndex<width-SpiralIndex; ColumnIndex++){
            Output.push_back(matrix[RowIndex][ColumnIndex]);
        }
        ColumnIndex--;
        
        for(RowIndex++; RowIndex<height-SpiralIndex; RowIndex++){
            Output.push_back(matrix[RowIndex][ColumnIndex]);
        }
    }
    
    return Output;
}
};


#include "gtest/gtest.h"

TEST( SpiralOrder, Tests )
{
    Solution solution{};
	
	vector<vector<int>> data;
	vector<int> expected;
	
	
	data = { {1,2,3}, {4,5,6}, {7,8,9} };
	expected = { 1,2,3,6,9,8,7,4,5 };
	EXPECT_EQ( solution.spiralOrder(data), expected );
	
	data = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	expected = { 1,2,3,4,8,12,11,10,9,5,6,7 };
	EXPECT_EQ( solution.spiralOrder(data), expected );
	
	data = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
	expected = { 1,2,3,4,5,10,15,14,13,12,11,6,7,8,9 };
	EXPECT_EQ( solution.spiralOrder(data), expected );
	
	data = { {1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15} };
	expected = { 1,2,3,6,9,12,15,14,13,10,7,4,5,8,11 };
	EXPECT_EQ( solution.spiralOrder(data), expected );
}
