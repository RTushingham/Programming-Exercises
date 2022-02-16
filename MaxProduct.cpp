#define debug 0

#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums) {
    
    int runningproduct=1;
    bool SeenANegative=0;
    int RunningproductAfterNegative=1;
    int Max=nums[0];
    
    for(int Index=0;Index<nums.size();Index++){
    	runningproduct *= nums[Index];
    	Max = Max>runningproduct ? Max : runningproduct;
    	
    	if(SeenANegative){
    		RunningproductAfterNegative *= nums[Index];
    		Max = Max>RunningproductAfterNegative ? Max : RunningproductAfterNegative;
		}
		
		if(!SeenANegative && nums[Index]<0){
			SeenANegative = 1;
		}
		if(nums[Index]==0){
			runningproduct=1;
			SeenANegative=0;
			RunningproductAfterNegative=1;
		}
	}
	return Max;
}

int main(int argc, char** argv) {
	cout << "Test Start." << endl;
	
	std::vector<int> data; 
	int result;
	int expected;
	
	
	data = { 2,3,-2,4 };
	result = maxProduct(data);
	expected = 6;
	cout << result << ", " << expected << endl;
	
	data = { -2,0,-1 };
	result = maxProduct(data);
	expected = 0;
	cout << result << ", " << expected << endl;
	
	
	data = { 2,3,-2,4,1,-1,-3,2,3 };
	result = maxProduct(data);
	expected = 72;
	cout << result << ", " << expected << endl;
	
	data = { -2,-1,-3 };
	result = maxProduct(data);
	expected = 3;
	cout << result << ", " << expected << endl;
	
	data = { 2,3,-2,4,-1,-1,-3,2,3 };
	result = maxProduct(data);
	expected = 864;
	cout << result << ", " << expected << endl;
	
	data = { -2,-1 };
	result = maxProduct(data);
	expected = 2;
	cout << result << ", " << expected << endl;
	
	data = { 2,1,3 };
	result = maxProduct(data);
	expected = 6;
	cout << result << ", " << expected << endl;
	
	data = { 0,2,1,3,0 };
	result = maxProduct(data);
	expected = 6;
	cout << result << ", " << expected << endl;
	
	data = { 0,0 };
	result = maxProduct(data);
	expected = 0;
	cout << result << ", " << expected << endl;
	
	data = { 2,-3,2,4 };
	result = maxProduct(data);
	expected = 8;
	cout << result << ", " << expected << endl;
	
	data = { -3 };
	result = maxProduct(data);
	expected = -3;
	cout << result << ", " << expected << endl;
	
	data = { 0,-3,0 };
	result = maxProduct(data);
	expected = 0;
	cout << result << ", " << expected << endl;
	
	data = { -3,2 };
	result = maxProduct(data);
	expected = 2;
	cout << result << ", " << expected << endl;
	
	data = { 3,-3 };
	result = maxProduct(data);
	expected = 3;
	cout << result << ", " << expected << endl;
	
	
	data = { 2,3,0,2,3,-2,4,1,-1,-3,2,3 };
	result = maxProduct(data);
	expected = 72;
	cout << result << ", " << expected << endl;
	
	
	return 0;
}
