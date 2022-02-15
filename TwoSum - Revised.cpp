#define debug 0

#include <iostream>

#include <unordered_map>

#include <vector>
using namespace std;

vector<int> TwoSumOn(vector<int>& nums, int target) {
    
    std::unordered_map<int, int> indexes;
    
    int Index;
	for(Index=0; indexes.count(target-nums[Index])==0 && Index<nums.size();Index++){
		if(indexes.count(nums[Index])==0){
			indexes.insert({nums[Index], Index});
		}
	}
	
    std::vector<int> Answer;
	Answer.resize(2);
	Answer = {indexes[target - nums[Index]], Index};
	return Answer;
}

int main(int argc, char** argv) {
	cout << "Test Start." << endl;
	
	std::vector<int> data; 
	int k;
	vector<int> result;
	
	data = { 2,7,11,15 };
	k = 9;
	result = TwoSumOn(data,k);
	cout << "["<< result[0] <<","<< result[1] << "] [0,1]" << endl;
	
	data = { 3,2,4 };
	k = 6;
	result = TwoSumOn(data,k);
	cout << "["<< result[0] <<","<< result[1] << "] [1,2]" << endl;
	
	data = { 3,3 };
	k = 6;
	result = TwoSumOn(data,k);
	cout << "["<< result[0] <<","<< result[1] << "] [0,1]" << endl;
	
	
	return 0;
}
