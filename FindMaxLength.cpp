#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

    int findMaxLength(std::vector<int>& nums) {
        
        std::vector<std::array<int, 2>> structre;
        structre.reserve(2*nums.size()+1);
        
        for(int Index = 0; Index<2*nums.size()+1; Index++){
        	structre[Index][0] = 0;
        	structre[Index][1] = 0;
		}
        
        int RunningSum=nums.size();
        
        for(int Index=0; Index<nums.size(); Index++){
            
            RunningSum += 2*nums[Index]-1;
            
            if( (structre[RunningSum][0]==0) && (RunningSum!=nums.size()) ){
            	structre[RunningSum][0] = Index+1;
			}
            structre[RunningSum][1] = Index+1;
            
        }
        
        int MaxLength=0;
        {
        	int Index=nums.size();
        	if(structre[Index][1]-structre[Index][0] > MaxLength){
            	MaxLength = structre[Index][1]-structre[Index][0];
        	}
		}
        
        for(int Index=nums.size()+1; Index<2*nums.size()+1 && structre[Index][1]!=0; Index++){
            
			if(structre[Index][1]-structre[Index][0] > MaxLength){
                MaxLength = structre[Index][1]-structre[Index][0];
            }
        }
        for(int Index=nums.size()-1; Index>=0 && structre[Index][1]!=0; Index--){
            
			if(structre[Index][1]-structre[Index][0] > MaxLength){
                MaxLength = structre[Index][1]-structre[Index][0];
            }
        }
        return MaxLength;
    }
    
int main(int argc, char** argv) {
	std::vector<int> data; 
	
	data = { 0,1 };
	cout << findMaxLength(data) << " 2" << endl;
	data = { 0,1,0 };
	cout << findMaxLength(data) << " 2" << endl;
	data = { 0,1,1 };
	cout << findMaxLength(data) << " 2" << endl;
	data = { 0,1,1,0,1,1,1,0 };
	cout << findMaxLength(data) << " 4" << endl;
	data = { 0,1,0,0,0,0 };
	cout << findMaxLength(data) << " 2" << endl;
	data = { 1,1,1,1,1,1,1 };
	cout << findMaxLength(data) << " 0" << endl;
	data = { 1,1,1,1,1,1,1,1 };
	cout << findMaxLength(data) << " 0" << endl;
	data = { 0,0,0,0,0,0,0 };
	cout << findMaxLength(data) << " 0" << endl;
	data = { 0,0,0,0,0,0,0,0 };
	cout << findMaxLength(data) << " 0" << endl;
	data = { 0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1 };
	cout << findMaxLength(data) << " 6" << endl;
	data = { 1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1 };
	cout << findMaxLength(data) << " 6" << endl;
	
	
	return 0;
}
