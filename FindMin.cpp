#define debug 0

#include <iostream>
#include <vector>
using namespace std;


int findMin(vector<int>& nums) {
    
    int FirstIndexOfSection = 0;
    int min = nums[FirstIndexOfSection];
    int LengthOfSection = nums.size();
    
    while(LengthOfSection>1){
        int CentreIndex = FirstIndexOfSection + LengthOfSection/2;
        if(nums[FirstIndexOfSection] > nums[CentreIndex]){
            LengthOfSection = CentreIndex - FirstIndexOfSection;
            min = nums[CentreIndex];
        }else{
            LengthOfSection = LengthOfSection + FirstIndexOfSection - CentreIndex;
            FirstIndexOfSection = CentreIndex;
        }
    }
	return min;
}


void PrintInt(int A){
	cout << A;
}
void CurrentTest(vector<int> D, int E){
	int result;
	result = findMin(D);
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
	
	vector<int> data;
	int expected;
	
	
	data = { 3,4,5,1,2 };
	expected = 1;
	CurrentTest(data, expected);
	
	
	data = { 2,3,4,5,1 };
	expected = 1;
	CurrentTest(data, expected);
	
	
	data = { 4,5,6,7,0,1,2 };
	expected = 0;
	CurrentTest(data, expected);
	
	
	data = { 11,13,15,17 };
	expected = 11;
	CurrentTest(data, expected);
	
	
	data = { 1,2,3 };
	expected = 1;
	CurrentTest(data, expected);
	
	data = { 1,2,3,4,5 };
	expected = 1;
	CurrentTest(data, expected);
	
	data = { 1,2,3,4,5,6,7 };
	expected = 1;
	CurrentTest(data, expected);
	
	data = { 1,2,3,4,5,6 };
	expected = 1;
	CurrentTest(data, expected);
	
	
	return 0;
}
