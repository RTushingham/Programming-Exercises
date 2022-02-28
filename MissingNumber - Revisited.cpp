#define debug 0

#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int RunningXor = 0;
    int Reference = nums.size();
    
    for(int Index=0; Index<nums.size(); Index++){
        RunningXor = RunningXor^nums[Index];
        Reference = Reference^Index;
    }
    return RunningXor^Reference;
}


void PrintInt(int A){
	cout << A;
}
void CurrentTest(std::vector<int> D, int E){
	int result;
	result = missingNumber(D);
	PrintInt(result);
	cout << ", ";
	PrintInt(E);
	cout << endl;
	
	if(E==result){
		cout << "These match." << endl;
	}else{
		cout << "These do not match." << endl;
	}
}


int main(int argc, char** argv) {
	
	cout << "Test Start." << endl;
	
	std::vector<int> data;
	int expected;
	
	
	data = { 3,0,1 };
	expected = 2;
	CurrentTest(data, expected);
	
	
	data = { 0,1 };
	expected = 2;
	CurrentTest(data, expected);
	
	
	data = { 9,6,4,2,3,5,7,0,1 };
	expected = 8;
	CurrentTest(data, expected);
	
	
	data = { 1 };
	expected = 0;
	CurrentTest(data, expected);
	
	
	data = { 1,2 };
	expected = 0;
	CurrentTest(data, expected);
	
	
	return 0;
}
