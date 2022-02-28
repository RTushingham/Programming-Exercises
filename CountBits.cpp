#define debug 0

#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n) {
    //vector<int>::vector(n+1) ans;
    
    vector<int> ans = {0};
    ans.reserve(n+1);
    
    if(n>0){
        ans.push_back(1);
    }
    
    int LoopLength=1;
    int Counter=1;
    
    for(int Index=0; Index<n-1; Index++){
        if(Counter == LoopLength){
            ans.push_back(1);
            Counter = 1;
            LoopLength *= 2;
        }else{
            ans.push_back(1+ans[Counter]);
            Counter++;
        }
    }
    
    return ans;
}


void PrintIntArray(vector<int> A){
	cout << "[";
	for(int Index=0; Index<(A.size()-1); Index++){
		cout << A.at(Index) << ", ";
	}
	cout << A.at(A.size()-1) << "]";
}
void CurrentTest(int D, std::vector<int> E, int *Q){
	std::vector<int> result;
	
	cout << "Test " << *Q++ << endl;
	result = countBits(D);
	PrintIntArray(result);
	cout << ", ";
	PrintIntArray(E);
	cout << endl;
	
	if(E==result){
		cout << "These match." << endl;
	}else{
		cout << "These do not match." << endl;
	}
}


int main(int argc, char** argv) {
	
	cout << "Test Start." << endl;
	
	int data;
	std::vector<int> expected;
	int QuestionCounter=0;
	
	
	data = 5;
	expected = { 0,1,1,2,1,2 };
	CurrentTest(data, expected, &QuestionCounter);
	
	
	data = 499;
	expected = { 0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8,5,6,6,7 };
	CurrentTest(data, expected, &QuestionCounter);
	
	
	return 0;
}
