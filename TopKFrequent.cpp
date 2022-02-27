#define debug 0

#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>

#include <iostream>
#include <vector>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    
    unordered_map<int,int> keytofrequency;
    
    for(const auto& num : nums){
    	
    	#if debug
    		cout << "num " << num << endl;
    	#endif
    	
    	keytofrequency[num]++;
	}
	
	vector<int> UniqueNums;
	for( const auto& pair : keytofrequency ){
		#if debug
            cout << "pair.first " << pair.first << ", pair.second " << pair.second << endl;
        #endif
		
		UniqueNums.push_back(pair.first);
	}
	
	unordered_set<int> VisitedValues;
	VisitedValues.insert(UniqueNums[0]);
	
	int ComparisonValue = keytofrequency[UniqueNums[0]];
	int NoOfBigger = UniqueNums.size();
	
	#if debug
    	cout << "ComparisonValue " << ComparisonValue << ", NoOfBigger " << NoOfBigger << endl;
    #endif
	
	while(NoOfBigger!=k){
		stack<int> BiggerValues;
		queue<int> SmallerValues;
		
		for(int Index=0; Index<UniqueNums.size(); Index++){
			#if debug
    			cout << "Index " << Index << ", ComparisonValue " << ComparisonValue << ", UniqueNums[Index] " << UniqueNums[Index] << ", keytofrequency[UniqueNums[Index]] " << keytofrequency[UniqueNums[Index]] << ", Comparison " << ComparisonValue>keytofrequency[UniqueNums[Index]] << endl;
		    #endif
		    
			if(ComparisonValue>keytofrequency[UniqueNums[Index]]){
				SmallerValues.push(Index);
			}else{
				BiggerValues.push(Index);
			}
		}
		
		NoOfBigger = BiggerValues.size();
		#if debug
    		cout << "NoOfBigger " << NoOfBigger << endl;
		#endif
		
		int InIndex;
		int OutIndex;
		
		#if debug
    		cout << "Max of Loop " << std::min(BiggerValues.size(), SmallerValues.size()) << endl;
		#endif
		
		int LoopIterations = std::min(BiggerValues.size(), SmallerValues.size());
        for(int Index=0; Index<LoopIterations; Index++){
			
			InIndex = BiggerValues.top();
			OutIndex = SmallerValues.front();
			
			#if debug
	    		cout << "InIndex " << InIndex << ", OutIndex " << OutIndex << endl;
			#endif
			
			if(InIndex>OutIndex){
				std::swap(UniqueNums[InIndex], UniqueNums[OutIndex]);
				BiggerValues.pop();
				SmallerValues.pop();
			}
		}
		
		if(NoOfBigger == k){
			break;
		}
		
		int dummy=NoOfBigger>k ? 0 : NoOfBigger;
		#if debug
    		cout << "dummy " << dummy <<", k "<<k<<", NoOfBigger "<<NoOfBigger<<", UniqueNums.size()-NoOfBigger "<<UniqueNums.size()-NoOfBigger << endl;
		#endif
		for(int Index=0; Index< (NoOfBigger>k ? NoOfBigger : (UniqueNums.size()-NoOfBigger)); Index++){
			#if debug
	    		cout << "dummy " << dummy << ", UniqueNums[dummy] " << UniqueNums[dummy] << ", VisitedValues.count(UniqueNums[dummy]) " << VisitedValues.count(UniqueNums[dummy]) << endl;
			#endif
			dummy += VisitedValues.count(UniqueNums[dummy])>0 ? 1:0;
		}
		
		ComparisonValue = keytofrequency[UniqueNums[dummy]];
		VisitedValues.insert(UniqueNums[dummy]);
		
		#if debug
	    	cout << "ComparisonValue " << ComparisonValue << endl;
		#endif
	}
	
	UniqueNums.resize(NoOfBigger);
	return UniqueNums;
}


int main(int argc, char** argv) {
	
	cout << "Test Start." << endl;
	
	std::vector<int> data;
	int k;
	std::vector<int> result;
	std::vector<int> expected;
	
	
	cout << "Test 1" << endl;
	data = { 1,1,1,2,2,3 };
	k = 2;
	result = topKFrequent(data,k);
	expected = { 1,2 };
	cout << "[";
	for(int Index=0; Index<result.size();Index++){
		cout << result[Index] << ", ";
	}
	cout << "], [";
	for(int Index=0; Index<expected.size();Index++){
		cout << expected[Index] << ", ";
	}
	cout << "]" << endl;
	
	
	cout << "Test 2" << endl;
	data = { 1 };
	k = 1;
	result = topKFrequent(data,k);
	expected = { 1 };
	cout << "[";
	for(int Index=0; Index<result.size();Index++){
		cout << result[Index] << ", ";
	}
	cout << "], [";
	for(int Index=0; Index<expected.size();Index++){
		cout << expected[Index] << ", ";
	}
	cout << "]" << endl;
	
	
	cout << "Test 3" << endl;
	data = { 6,8,3,4,3,2,4,8,5,8,1,2,1,8,8,2,4,9,4,4,3,1,6,9,5,8,1,3,10,1,9,4,1,9,1,3,4,7,8,6,3,9,4,9,3,2,6,7,6,2,2,1,5,2,2,4,5,10,10,5,7,3,5,1,2,6,9,3,5,4,2,4,7,9,8,6,10,6,7,3,1,9,3,7,7,5,3,3,8,4,4,4,8,7,5,6,8,10,3,0,7,1,8,0,2,1,9,1,4,3,5,8,7,7,1,3,1,8,5,7,8,2,1,3,8,0,9,7,7,6 };
	k = 3;
	result = topKFrequent(data,k);
	expected = { 8,1,3 };
	cout << "[";
	for(int Index=0; Index<result.size();Index++){
		cout << result[Index] << ", ";
	}
	cout << "], [";
	for(int Index=0; Index<expected.size();Index++){
		cout << expected[Index] << ", ";
	}
	cout << "]" << endl;
	
	
	cout << "Test 4" << endl;
	data = { 3,0,1,0 };
	k = 1;
	result = topKFrequent(data,k);
	expected = { 0 };
	cout << "[";
	for(int Index=0; Index<result.size();Index++){
		cout << result[Index] << ", ";
	}
	cout << "], [";
	for(int Index=0; Index<expected.size();Index++){
		cout << expected[Index] << ", ";
	}
	cout << "]" << endl;
	
	
	cout << "Test 5" << endl;
	data = { 6,2,5,6,0,3,8,8,10,6,0,4,9,5,9,6,2,4,1,5,5,4,1,9,2,3,1,5,9,8,8,3,1,8,1,2,3,8,7,10,8,4,0,7,6,0,3,10,6,4,1,4,9,9,1,10,9,9,5,7,6,8,1,9,6,4,6,9,6,9,4,8,9,0,2,8,6,1,9,9,5,9,3,2,1,7,7,4,6,7,4,1,5,10,6,10,10,6,7,6,5,10,7,2,8,7,4,10,3,2,4,10,4,1,2,6,8,5,4,3,3,9,4,6,7,3,6,2,0,4 };
	k = 3;
	result = topKFrequent(data,k);
	expected = { 6,4,9 };
	cout << "[";
	for(int Index=0; Index<result.size();Index++){
		cout << result[Index] << ", ";
	}
	cout << "], [";
	for(int Index=0; Index<expected.size();Index++){
		cout << expected[Index] << ", ";
	}
	cout << "]" << endl;
	
	
	cout << "Test 6" << endl;
	data = { 5,3,1,1,1,3,5,73,1 };
	k = 3;
	result = topKFrequent(data,k);
	expected = { 1,3,5 };
	cout << "[";
	for(int Index=0; Index<result.size();Index++){
		cout << result[Index] << ", ";
	}
	cout << "], [";
	for(int Index=0; Index<expected.size();Index++){
		cout << expected[Index] << ", ";
	}
	cout << "]" << endl;
	
	
	cout << "Test 7" << endl;
	data = { 6,0,1,4,9,7,-3,1,-4,-8,4,-7,-3,3,2,-3,9,5,-4,0 };
	k = 6;
	result = topKFrequent(data,k);
	expected = { -3,-4,0,1,4,9 };
	cout << "[";
	for(int Index=0; Index<result.size();Index++){
		cout << result[Index] << ", ";
	}
	cout << "], [";
	for(int Index=0; Index<expected.size();Index++){
		cout << expected[Index] << ", ";
	}
	cout << "]" << endl;
	
	return 0;
}
