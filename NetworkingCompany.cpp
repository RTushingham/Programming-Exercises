#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

// Wasn't required by the interview
constexpr int int_pow(int base, int exponent)
{
	return exponent == 0 ? 1 : base*int_pow(base,exponent-1);
}

// Assumes N is a positive integer less than 1000, K is a positive integer.
// Finds the largest value less than 1000 which you could make N into if you were to increment the decimals by a total of K.
int solution(int N, int K);
int solution(int number_to_maximise, int budget_for_digit_increments) 
{
	std::array<int,4> powers_of_ten = {int_pow(10,0),int_pow(10,1),int_pow(10,2),int_pow(10,3)};
	
    for(int decimal_index=3; decimal_index>0; decimal_index--)
    {
    	int current_digit = (number_to_maximise % powers_of_ten[decimal_index]) / powers_of_ten[decimal_index-1];
    	int current_digit_can_increment_by = std::min( 9 - current_digit, budget_for_digit_increments );

        budget_for_digit_increments -= current_digit_can_increment_by;
        number_to_maximise += powers_of_ten[decimal_index-1] * current_digit_can_increment_by;
    }
    return number_to_maximise;
}

// N assumed to be 30 bit integer.
// Finds the largest rightward rotation which produces the largest value, and how many times it needs to be rotated by to get there.
int solution(const int N)
{
    int current_rotation_value = N;
    int largest_value = N;
    int index_of_biggest_value = 0;
    
    for (int shift_index = 1; shift_index < 30; ++shift_index) 
	{
        int least_significant_bit = (current_rotation_value & 0b1);
        current_rotation_value = ((current_rotation_value >> 1) | (least_significant_bit << 29));

        if (current_rotation_value > largest_value) {
            largest_value = current_rotation_value;
            index_of_biggest_value = shift_index;
        }
    }
    return index_of_biggest_value;
}

int main(int argc, char** argv) {
	cout << "int_pow(10, 0): " << int_pow(10, 0) << ", expected: 1" << endl;
	cout << "int_pow(10, 1): " << int_pow(10, 1) << ", expected: 10" << endl;
	cout << "int_pow(10, 2): " << int_pow(10, 2) << ", expected: 100" << endl;
	cout << "int_pow(10, 3): " << int_pow(10, 3) << ", expected: 1000" << endl;
		
	
	cout << "solution(001, 5): " << solution(001, 5) << ", expected: 501" << endl;
	cout << "solution(444, 7): " << solution(444, 7) << ", expected: 964" << endl;
	cout << "solution(613, 12): " << solution(613, 12) << ", expected: 994" << endl;
	cout << "solution(891, 2): " << solution(891, 2) << ", expected: 992" << endl;
	cout << "solution(981, 3): " << solution(981, 3) << ", expected: 993" << endl;
	
	cout << "solution(0b10000): " << solution(0b10000) << ", expected: 5" << endl;
	cout << "solution(0b10110): " << solution(0b10110) << ", expected: 3" << endl;
	cout << "solution(0b000000011000000001100000000000): " << solution(0b000000011000000001100000000000) << ", expected: 23" << endl;
	cout << "solution(0b101101011010110101101011010110): " << solution(0b101101011010110101101011010110) << ", expected: any value which equals 3 modulo 5" << endl;

	return 0;
}

