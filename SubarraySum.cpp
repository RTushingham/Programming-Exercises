#define debug 0

#include <iostream>

#include <vector>
#include <unordered_map>
using namespace std;

int SubarraySum(vector<int>& nums, int k) {
    
    	std::unordered_map<int,std::vector<int>> Visits;
        
        int RunningSum=0;
        Visits[0].push_back(0);
        
        for(int Index=0;Index<nums.size();Index++){
        	#if debug
                cout << "Before Recording: " << nums.at(Index) << " nums.at(Index) " << RunningSum << " RunningSum" << endl;
            #endif
            
            RunningSum += nums.at(Index);
            Visits[RunningSum].push_back(Index+1);
            
            #if debug
                cout << "After Recording: " << RunningSum << " RunningSum " << Visits[RunningSum].size() << " Visits[RunningSum].size() " << Index+1 << " Index+1 " << endl;
            #endif
        }
        
        int ReturnValue=0;
        if(k!=0){
        	for( const auto& key : Visits ) {
	        	
    	    	#if debug
        	        cout << "Before if: " << key.first << " key " << key.first+k << " key+k " << Visits[key.first].size() << " Visits[key].size() " << Visits.count(key.first+k) << " Visits.count(key+k) " << endl;
            	#endif
            	
	            if(Visits.count(key.first+k)!=0){
    	        	
        	    	#if debug
            	        cout << "Inside if before: " << key.first << " key " << Visits[key.first].size() << " Visits[key].size() " << Visits[key.first+k].size() << " Visits[key+k].size() " << ReturnValue << " ReturnValue " << endl;
                	#endif
                	
	            	std::vector<int> LargerGroup = Visits[key.first+k];
	            	std::vector<int> SmallerGroup = Visits[key.first];
	            	int IndexForLargerGroup = 0;
					int IndexForSmallerGroup = 0;
	            	while(IndexForLargerGroup<LargerGroup.size() && IndexForSmallerGroup<SmallerGroup.size()){
						
						#if debug
            	        	cout << "Inside loop before: " << ReturnValue << " ReturnValue " << IndexForLargerGroup << " IndexForLargerGroup " << IndexForSmallerGroup << " IndexForSmallerGroup " << LargerGroup[IndexForLargerGroup] << " LargerGroup[IndexForLargerGroup] " << SmallerGroup[IndexForSmallerGroup] << " SmallerGroup[IndexForSmallerGroup] " << endl;
	                	#endif
						
						bool NextLargerGroupWasLater = LargerGroup[IndexForLargerGroup]>SmallerGroup[IndexForSmallerGroup];
						
						ReturnValue += NextLargerGroupWasLater ? LargerGroup.size()-IndexForLargerGroup : 0;
						IndexForLargerGroup += NextLargerGroupWasLater ? 0 : 1;
						IndexForSmallerGroup += NextLargerGroupWasLater ? 1 : 0;
						
						#if debug
            	        	cout << "Inside loop after: " << ReturnValue << " ReturnValue " << IndexForLargerGroup << " IndexForLargerGroup " << IndexForSmallerGroup << " IndexForSmallerGroup " << endl;
	                	#endif
					}
    	        	
        	    	#if debug
            	        cout << "Inside if after: " << ReturnValue << " ReturnValue " << endl;
                	#endif
	            }
    	    }
		}else{
			for( const auto& key : Visits ) {
				
				int value = Visits[key.first].size();
				
                #if debug
                    cout << "Before: " << ReturnValue << " ReturnValue " << key.first << " key " << value << " value " << (value-1)/2 << " (value/2)*(value-1) " << (value/2)*(value-1) << " (value-1)/2 " << endl;
                #endif

                ReturnValue += value%2==1? ((value-1)/2)*value : (value/2)*(value-1);

                #if debug
                    cout << "After: " << ReturnValue << " ReturnValue " << endl;
                #endif
            }
		}
		
        return ReturnValue;
}

	/*
        #if __cplusplus > 201402L
        	for( const auto& [key, value] : Visits ) {
        #if __cplusplus > 201703L
            if(Visits.Contains(key+k)){
    */

int main(int argc, char** argv) {
	std::vector<int> data; 
	int k;
	
	data = { 1,1,1 };
	k = 2;
	cout << SubarraySum(data,k) << " 2" << endl;
	
	data = { 1,2,3 };
	k = 3;
	cout << SubarraySum(data,k) << " 2" << endl;
	
	data = { 1,-1,1,-1 };
	k = 0;
	cout << SubarraySum(data,k) << " 4" << endl;
	
	data = { -1,-1,1 };
	k = 1;
	cout << SubarraySum(data,k) << " 1" << endl;
	
	data = { 1,2,3 };
	k = -1;
	cout << SubarraySum(data,k) << " 0" << endl;
	
	data = { 2,-2,2,-2 };
	k = 2;
	cout << SubarraySum(data,k) << " 3" << endl;
	
	data = { 1,-1,2,-2,2,-2 };
	k = 2;
	cout << SubarraySum(data,k) << " 5" << endl;
	
	data = { 1,-1,2,-2,2,-1,1,-2 };
	k = 2;
	cout << SubarraySum(data,k) << " 8" << endl;
	
	return 0;
}
