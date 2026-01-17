#include <functional>
#include <numeric>
#include <vector>

constexpr int running_bit_xor( int n )
{
    return n == 0 ? 0 : n ^ running_bit_xor( n - 1 );
}

// Given an array containing n distinct numbers in the range [0, n], return the only number in the range that is missing.
int missingNumber(const std::vector<int>& nums) {
    return running_bit_xor( nums.size() ) ^ std::accumulate( nums.cbegin(), nums.cend(), 0, std::bit_xor<int>() );
}


#include <iostream>
using namespace std;

void PrintInt(int A){
	cout << A;
}
void CurrentTest(std::vector<int> D, int E){
	int result;
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
	
	
	data = { 3,0,1 };
	expected = 2;
	CurrentTest(data, expected);
	
	
	data = { 0,1 };
	expected = 2;
	CurrentTest(data, expected);
	
	
	data = { 9,6,4,2,3,5,7,0,1 };
	expected = 8;
	CurrentTest(data, expected);
	
	
	data = { 1 };
	expected = 0;
	CurrentTest(data, expected);
	
	
	data = { 1,2 };
	expected = 0;
	CurrentTest(data, expected);
	
	
	return 0;
}
