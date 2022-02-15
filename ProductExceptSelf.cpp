#define debug 1

#include <iostream>

#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    
    vector<int> BottomTriangle;
    BottomTriangle.resize(nums.size());
    
    int runningproduct=1;
    for(int Index=nums.size()-1;Index>0;Index--){
        BottomTriangle[Index] = runningproduct;
        runningproduct*=nums[Index];
    }
    BottomTriangle[0] = runningproduct;
    
    int PreviousProduct=1;
    runningproduct=1;
    
    for(int Index=0;Index<nums.size();Index++){
    	
    	#if debug
    		cout << Index << " Index " << runningproduct << " runningproduct "<< nums[Index] << " nums[Index] " << endl;
    	#endif
    	
        runningproduct *= nums[Index];
        
        #if debug
    		cout << runningproduct << " runningproduct " << endl;
    		cout << nums[Index] << " nums[Index] " << BottomTriangle[Index] << " BottomTriangle[Index] " << PreviousProduct << " PreviousProduct " << BottomTriangle[Index]*PreviousProduct << " BottomTriangle[Index]*PreviousProduct " << endl;
    	#endif
        
        nums[Index] = BottomTriangle[Index]*PreviousProduct;
        
        #if debug
    		cout << nums[Index] << " nums[Index] " << endl;
    		cout << PreviousProduct << " PreviousProduct " << runningproduct << " runningproduct " << endl;
    	#endif
        
        PreviousProduct = runningproduct;
        
        #if debug
    		cout << PreviousProduct << " PreviousProduct " << endl;
    	#endif
    }
    
    return nums;
}

int main(int argc, char** argv) {
	cout << "Test Start." << endl;
	
	std::vector<int> data;
	vector<int> result;
	
	data = { 1,2,3,4 };
	result = productExceptSelf(data);
	cout << "[";
	for(int Index=0;Index<result.size()-1;Index++){
		cout << result[Index] << ", ";
	}
	cout << result[result.size()-1];
	cout << "]"<< endl;
	
	data = { -1,1,0,-3,3 };
	result = productExceptSelf(data);
	cout << "[";
	for(int Index=0;Index<result.size()-1;Index++){
		cout << result[Index] << ", ";
	}
	cout << result[result.size()-1];
	cout << "]"<< endl;
	
	
	return 0;
}
