#define debug 0

#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    
    int max = std::max(m,n);
    int min = std::min(m,n);
    
    long long runningproduct=1;
    int divisor=1;
    
    for(int Multiplier=max; Multiplier<m+n-1; Multiplier++, divisor++){
        runningproduct *= Multiplier;
		runningproduct /= divisor;
    }
    return (int)runningproduct;
}


void PrintInt(int A){
	cout << A;
}
void CurrentTest(vector<int> D, int E){
	int result;
	result = uniquePaths(D[0], D[1]);
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
	
	
	data = { 1,1 };
	expected = 1;
	CurrentTest(data, expected);
	
	
	data = { 3,7 };
	expected = 28;
	CurrentTest(data, expected);
	
	
	data = { 3,2 };
	expected = 3;
	CurrentTest(data, expected);
	
	
	data = { 10,10 };
	expected = 48620;
	CurrentTest(data, expected);
	
	
	data = { 51,9 };
	expected = 1916797311;
	CurrentTest(data, expected);
	
	
	return 0;
}
