#include <vector>

int combinationSum4(vector<int>& nums, int target) {
    
    vector<unsigned> SetsOfSumIndex(target+1, 0);
    SetsOfSumIndex[0]=1;
    
    for(int Index=1; Index <= target; Index++)
    {
        for(auto num:nums)
        {
            if(num<=Index)
            {
                SetsOfSumIndex[Index] += SetsOfSumIndex[Index-num];
            }
        }
    }
    
    return SetsOfSumIndex[target];
}
