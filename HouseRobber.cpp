
#include <vector>
using namespace std;

// O(n) complexity, O(n) memory - but faster
int rob(vector<int>& nums) {
    int MaxIndex = nums.size();
    if(MaxIndex == 1)
        return nums[0];
    
    vector<int> ExcludingPrevious(MaxIndex), IncludingPrevious(MaxIndex);
    IncludingPrevious[1] = nums[1];
    ExcludingPrevious[1] = nums[0];
    
    for(int Index = 2; Index < MaxIndex; Index++)
    {
        ExcludingPrevious[Index] = max(ExcludingPrevious[Index-1], IncludingPrevious[Index-1]);
        IncludingPrevious[Index] = ExcludingPrevious[Index-1] + nums[Index];
    }
    
    return max(ExcludingPrevious[MaxIndex-1], IncludingPrevious[MaxIndex-1]);
}

// O(n) complexity, O(1) memory - but slower
int rob(vector<int>& nums) {
	int MaxIndex = nums.size();
    if(MaxIndex == 1)
        return nums[0];
    
    int ExcludingPrevious = nums[0], IncludingPrevious = nums[1], temp;
    
    for(int Index = 2; Index < MaxIndex; Index++)
    {
        temp = ExcludingPrevious + nums[Index];
        
        ExcludingPrevious = max(ExcludingPrevious, IncludingPrevious);
        IncludingPrevious = temp;
    }
    
    return max(ExcludingPrevious, IncludingPrevious);
}

