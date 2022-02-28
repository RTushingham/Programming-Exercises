#define debug 0

#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    
    int n = nums.size();
    
    for(int num : nums){
    	
    	#if debug
    		cout << "num " << num << ", (num+n+1) " << (num+n+1) << ", (num+n+1)%(n+1) "<< (num+n+1)%(n+1) << ", nums[(num+n+1)%(n+1)] " << nums[(num+n+1)%(n+1)] << endl;
    	#endif
    	
        if((num+n+1)%(n+1)!=n){
        	#if debug
                cout << "Bruh" << endl;
            #endif
            
            nums[(num+n+1)%(n+1)] -= n+1;
        }
    }
    
    int ReturnValue=0;
    for(int num : nums){
    	#if debug
    		cout << "ReturnValue " << ReturnValue << ", nums[ReturnValue] " << nums[ReturnValue]<< endl;
    	#endif
        ReturnValue += nums[ReturnValue]<0 ? 1 : 0;
    }
    #if debug
    	cout << "ReturnValue " << ReturnValue << endl;
    #endif
    return ReturnValue;
}


void PrintInt(int A){
	cout << A;
}
void CurrentTest(std::vector<int> D, int E, int* Q){
	int result;
	
	cout << "Test " << *Q++ << endl;
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
	int QuestionCounter=0;
	
	
	data = { 3,0,1 };
	expected = 2;
	CurrentTest(data, expected, &QuestionCounter);
	
	
	data = { 0,1 };
	expected = 2;
	CurrentTest(data, expected, &QuestionCounter);
	
	
	data = { 9,6,4,2,3,5,7,0,1 };
	expected = 8;
	CurrentTest(data, expected, &QuestionCounter);
	
	
	data = { 1 };
	expected = 0;
	CurrentTest(data, expected, &QuestionCounter);
	
	
	data = { 1,2 };
	expected = 0;
	CurrentTest(data, expected, &QuestionCounter);
	
	
	return 0;
}
