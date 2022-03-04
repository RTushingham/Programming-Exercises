#define debug 0

#include <iostream>
#include <vector>
using namespace std;

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


void PrintIntArray(vector<int> A){
	cout << "[";
	for(int Index=0; Index<(A.size()-1); Index++){
		cout << A.at(Index) << ", ";
	}
	cout << A.at(A.size()-1) << "]";
}

void CurrentTest(std::vector<vector<int>> D, vector<int> E){
	vector<int> result;
	result = spiralOrder(D);
	PrintIntArray(result);
	cout << ", ";
	PrintIntArray(E);
	cout << endl;
	
	if(E==result){
		cout << "These match." << endl;
	}else{
		cout << "These do not match." << endl;
	}
}


int main(int argc, char** argv) {
	
	cout << "Test Start." << endl;
	
	vector<vector<int>> data;
	vector<int> expected;
	
	
	data = { {1,2,3}, {4,5,6}, {7,8,9} };
	expected = { 1,2,3,6,9,8,7,4,5 };
	CurrentTest(data, expected);
	
	
	data = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	expected = { 1,2,3,4,8,12,11,10,9,5,6,7 };
	CurrentTest(data, expected);
	
	
	data = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
	expected = { 1,2,3,4,5,10,15,14,13,12,11,6,7,8,9 };
	CurrentTest(data, expected);
	
	data = { {1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15} };
	expected = { 1,2,3,6,9,12,15,14,13,10,7,4,5,8,11 };
	CurrentTest(data, expected);
	
	
	return 0;
}
