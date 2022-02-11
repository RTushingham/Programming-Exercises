
#define debug 0

#include <iostream>

#include <vector>
#include <unordered_map>
using namespace std;

int FindPairs(vector<int>& nums, int k) {
    
    	int returnvalue=0;
        #if __cplusplus > 201703L
            std::unordered_map<int, bool> FoundResults;
        #else //if __cplusplus < 201703L and __cplusplus >= 201103L
            std::unordered_map<int, bool> FoundResults;
        #endif
        
        FoundResults.reserve(nums.size());
        
        if(k!=0){
	        for(int Index=0;Index<nums.size();Index++){
    	        
            	#if __cplusplus > 201703L
                	if(!(FoundResults.contains(nums[Index]))){
                    	FoundResults.insert({nums[Index], 1});
	                }
    	            
        	        if(FoundResults[nums[Index]]==1 && FoundResults.contains(nums[Index]+k)){
            	        returnvalue++;
                	    FoundResults[nums[Index]]=0;
	                }
	
    	            if(FoundResults.contains(nums[Index]-k) && FoundResults[nums[Index]-k]==1){
        	            returnvalue++;
            	        FoundResults[nums[Index]-k]=0;
                	}
	            #else
    	        
            		#if debug
            			cout << Index << " Index, " << nums[Index] << " nums[Index]" << endl;
	            		cout << FoundResults.count(nums[Index]) << " FoundResults.count(nums[Index])" << endl;
    	        	#endif
        	    
            	    if(FoundResults.count(nums[Index])==0){
                		
                    	FoundResults.insert({nums[Index], 1});
	                    
						#if debug
        	            	cout << "First Entry: " << nums[Index] << " nums[Index]" << endl;
            	        #endif
                	}
	                
    	            #if debug
        	        	cout << nums[Index] << " nums[Index], " << FoundResults.count(nums[Index]+k) << " FoundResults.count(nums[Index]+k)" << endl;
            	    #endif
                	
	                if(FoundResults[nums[Index]]==1 && FoundResults.count(nums[Index]+k)>0){
    	                
        	            #if debug
            	        	cout << "Looked Forwards: " << returnvalue << " returnvalue, " << FoundResults[nums[Index]] << " FoundResults[nums[Index]]" << endl;
                	    #endif
                    	
	                    returnvalue++;
    	                FoundResults[nums[Index]]=0;
        	            
            	        #if debug
                	    	cout << returnvalue << " returnvalue, " << FoundResults[nums[Index]] << " FoundResults[nums[Index]]" << endl;
                    	#endif
	                }
					
					#if debug
						cout << k << " k, " << FoundResults.count(nums[Index]-k) << " FoundResults[nums[Index]-k]" << endl;
					#endif
					
	                if(FoundResults.count(nums[Index]-k)>0 && FoundResults[nums[Index]-k]==1){
    	            	
        	        	#if debug
            	    		cout <<  "Looked Backwards: " << returnvalue << " returnvalue, " << FoundResults[nums[Index]-k] << " FoundResults[nums[Index]-k]" << endl;
                		#endif
                		
	                    returnvalue++;
    	                FoundResults[nums[Index]-k]=0;
        	            
            	        #if debug
                	    	cout << returnvalue << " returnvalue, " << FoundResults[nums[Index]-k] << " FoundResults[nums[Index]-k]" << endl;
                    	#endif
	                }
	                
    	        	#if debug
        	    		cout << "Next Index" << endl;
            		#endif
        		
	            #endif
        	}
        }else{
        	for(int Index=0;Index<nums.size();Index++){
    	        
            	#if __cplusplus > 201703L
                	if(!(FoundResults.contains(nums[Index]))){
                    	FoundResults.insert({nums[Index], 1});
	                }else if(FoundResults[nums[Index]]==1){
	                	returnvalue++;
	                	FoundResults[nums[Index]]=0;
	            	}
	            #else
    	        
            		#if debug
            			cout << Index << " Index, " << nums[Index] << " nums[Index]" << endl;
	            		cout << FoundResults.count(nums[Index]) << " FoundResults.count(nums[Index])" << endl;
    	        	#endif
        	    
            	    if(FoundResults.count(nums[Index])==0){
                		
                    	FoundResults.insert({nums[Index], 1});
	                    
						#if debug
        	            	cout << "First Entry: " << nums[Index] << " nums[Index]" << endl;
            	        #endif
                	}else if(FoundResults[nums[Index]]==1){
                		
                		#if debug
                		cout << "First Repeat: " << returnvalue << " returnvalue, " << FoundResults[nums[Index]] << " FoundResults[nums[Index]]" << endl;
                		#endif
                		
                		returnvalue++;
                		FoundResults[nums[Index]]=0;
                		
                		#if debug
                		cout << returnvalue << " returnvalue, " << FoundResults[nums[Index]] << " FoundResults[nums[Index]]" << endl;
                		#endif
					}
					
					#if debug
        	    		cout << "Next Index" << endl;
            		#endif
					
	            #endif
        	}
		}
        return returnvalue;
}

int main(int argc, char** argv) {
	std::vector<int> data; 
	int k;
	
	data = { 0,1 };
	k = 1;
	cout << FindPairs(data,k) << " 1" << endl;
	
	data = { 3,1,4,1,5 };
	k = 2;
	cout << FindPairs(data,k) << " 2" << endl;
	
	data = { 1,2,3,4,5 };
	k = 1;
	cout << FindPairs(data,k) << " 4" << endl;
	
	data = { 3,1,4,1,5 };
	k = 0;
	cout << FindPairs(data,k) << " 1" << endl;
	
	data = { -1,-2,-3 };
	k = 1;
	cout << FindPairs(data,k) << " 2" << endl;
	
	data = { 3,2,1 };
	k = 1;
	cout << FindPairs(data,k) << " 2" << endl;
	
	return 0;
}
