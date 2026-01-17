class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ReturnValue=0;
        while(n)
        {
            n &= (n-1);
            ReturnValue++;
        }
        return ReturnValue;
    }
};


