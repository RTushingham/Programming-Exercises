
#include <algorithm>

int solution(int N, int K) {
    int dividing_factor = 100;
    int subtraction_factor = 0;

    for(int digit_index=3; digit_index>0 && digit_index<4 && K>0; digit_index--){
        int decimalinquestion = (std::min(9-(N-subtraction_factor)/dividing_factor, K));
        N += dividing_factor * decimalinquestion;
        K -= decimalinquestion;
        subtraction_factor += 9*dividing_factor;
        dividing_factor /= 10;
    }
    return N;
}

int solution(int N) {
    int largest = N;
    int shift = 0;
    int temp = N;
    for (int i = 1; i < 30; ++i) {
        int index = (temp & 1);
        temp = ((temp >> 1) | (index << 29));
        if (temp > largest) {
            largest = temp;
            shift = i;
        }
    }
    return shift;
}

