#include <algorithm>
#include <iostream>
using namespace std;

// Assumes N is a positive integer less then 1000, K is a positive integer.
// Finds the largest value you could make N into if you were to 'add K digets to it'.
int solution(int N, int K) {
    int dividing_factor = 100;
    int subtraction_factor = 0;

    for(int digit_index=3; digit_index>0 && digit_index<4 && K>0; digit_index--){
        int decimal_in_question = (std::min(9-(N-subtraction_factor)/dividing_factor, K));

        N += dividing_factor * decimal_in_question;
        K -= decimal_in_question;
        
		subtraction_factor += 9*dividing_factor;
        dividing_factor /= 10;
    }
    return N;
}

// N assumed to be 30 bit integer.
// Finds the largest rightward rotation which produces the largest value, and how many times it needs to be rotated by to get there.
int solution(int N) {
    int current_rotation_value = N;
    int largest_value = N;
    int index_of_biggest_value = 0;
    
    for (int shift_index = 1; shift_index < 30; ++shift_index) {

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
	cout << "solution(001, 5): " << solution(001, 5) << ", expected: 501" << endl;
	cout << "solution(444, 7): " << solution(444, 7) << ", expected: 964" << endl;
	
	cout << "solution(0b10000): " << solution(0b10000) << ", expected: 5" << endl;
	cout << "solution(0b10110): " << solution(0b10110) << ", expected: 3" << endl;
	cout << "solution(0b000000011000000001100000000000): " << solution(0b000000011000000001100000000000) << ", expected: 23" << endl;
	cout << "solution(0b101101011010110101101011010110): " << solution(0b101101011010110101101011010110) << ", expected: any value which equals 3 modulo 5" << endl;

	return 0;
}

