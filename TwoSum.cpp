#define debug 0

#include <iostream>

#include <algorithm>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    
    std::vector<int> old;
    
    for(int Index=0;Index<nums.size();Index++){
    	
    	old.push_back(nums[Index]);
        
        #if debug
            cout << "Creating Old: " << old.at(Index) << " old.at(Index) " << endl;
        #endif
    }
    
    std::sort(nums.begin(), nums.end());
    
    #if debug
    	for(int Index=0;Index<nums.size();Index++){
        	cout << "Sorted nums: " << nums.at(Index) << " nums.at(Index) " << endl;
    	}
    #endif
    
    int UpperIndex = nums.size()-1;
    int LowerIndex = 0;
    
    #if debug
        cout << "Before Loop: " << UpperIndex << " UpperIndex " << LowerIndex << " LowerIndex " << endl;
        cout << "Before While Loop: " << nums[UpperIndex] << " nums[UpperIndex] " << nums[LowerIndex] << " nums[LowerIndex] " << nums.size() << " nums.size() " << endl;
    #endif
    
    while( (nums[UpperIndex]+nums[LowerIndex])!=target && LowerIndex<UpperIndex){
        
        if(nums.at(UpperIndex)+nums.at(LowerIndex) > target ){
            UpperIndex--;
        }
        if(nums.at(UpperIndex)+nums.at(LowerIndex) < target ){
            LowerIndex++;
        }
        
        #if debug
        	cout << "Inside While Loop: " << UpperIndex << " UpperIndex " << LowerIndex << " LowerIndex " << endl;
        	cout << nums[UpperIndex] << " nums[UpperIndex] " << nums[LowerIndex] << " nums[LowerIndex] " << nums.size() << " nums.size() " << endl;
    	#endif
    }
    
    vector<int> Answer;
    Answer.reserve(2);
    
    int Index=0;
    
	#if debug
    	cout << "Before Searching: " << Index << " Index " << endl;
	#endif
    
	for(Index=0; (old[Index]!=nums[LowerIndex] && old[Index]!=nums[UpperIndex]) && Index<old.size();Index++){
		#if debug
        	cout << "First Search: " << Index << " Index " << endl;
        	cout << old[Index] << " old[Index] " << nums[LowerIndex] << " nums[LowerIndex]" << nums[UpperIndex] << " nums[UpperIndex] " << endl;
	    #endif
    }
    int indexone = Index;
    
	#if debug
    	cout << "After First Search: " << Index << " Index " << indexone << " indexone" << endl;
	    cout << old[Index] << " old[Index] " << nums[LowerIndex] << " nums[LowerIndex]" << nums[UpperIndex] << " nums[UpperIndex] " << endl;
    #endif
	
    for(Index=Index+1; (old[Index]!=nums[LowerIndex] && old[Index]!=nums[UpperIndex]) && Index<old.size();Index++){
        #if debug
        	cout << "Second Search: " << Index << " Index " << endl;
        	cout << old[Index] << " old[Index] " << nums[LowerIndex] << " nums[LowerIndex]" << nums[UpperIndex] << " nums[UpperIndex] " << endl;
	    #endif
    }
	int indextwo = Index;
    
	#if debug
    	cout << "After Second Search: " << Index << " Index " << indextwo << " indextwo" << endl;
    #endif
    
    Answer.push_back( (indexone<indextwo) ? indexone : indextwo );
    Answer.push_back( (indexone<indextwo) ? indextwo : indexone );
    
    return Answer;
}

int main(int argc, char** argv) {
	cout << "Test Start." << endl;
	
	std::vector<int> data; 
	int k;
	vector<int> result;
	
	data = { 2,7,11,15 };
	k = 9;
	result = twoSum(data,k);
	cout << "["<< result[0] <<","<< result[1] << "] [0,1]" << endl;
	
	data = { 3,2,4 };
	k = 6;
	result = twoSum(data,k);
	cout << "["<< result[0] <<","<< result[1] << "] [1,2]" << endl;
	
	data = { 3,3 };
	k = 6;
	result = twoSum(data,k);
	cout << "["<< result[0] <<","<< result[1] << "] [0,1]" << endl;
	
	
	return 0;
}
