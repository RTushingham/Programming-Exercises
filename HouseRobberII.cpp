int rob(vector<int>& nums) {
    int MaxIncludingPreviousIncZero = 0, MaxExcludingPreviousIncZero = 0, dummyIncZero;
    int MaxIncludingPreviousExZero = 0, MaxExcludingPreviousExZero = 0, dummyExZero;
    int LoopMax = nums.size()-1;
    
    dummyIncZero = MaxExcludingPreviousIncZero + nums[0];
    MaxExcludingPreviousIncZero = max(MaxIncludingPreviousIncZero, MaxExcludingPreviousIncZero);
    MaxIncludingPreviousIncZero = dummyIncZero;
    
    for(int Index=1; Index<LoopMax; Index++)
    {
        dummyIncZero = MaxExcludingPreviousIncZero + nums[Index];
        MaxExcludingPreviousIncZero = max(MaxIncludingPreviousIncZero, MaxExcludingPreviousIncZero);
        MaxIncludingPreviousIncZero = dummyIncZero;
        
        dummyExZero = MaxExcludingPreviousExZero + nums[Index];
        MaxExcludingPreviousExZero = max(MaxIncludingPreviousExZero, MaxExcludingPreviousExZero);
        MaxIncludingPreviousExZero = dummyExZero;
    }
    if(LoopMax>0)
    {
        dummyExZero = MaxExcludingPreviousExZero + nums[LoopMax];
        MaxExcludingPreviousExZero = max(MaxIncludingPreviousExZero, MaxExcludingPreviousExZero);
        MaxIncludingPreviousExZero = dummyExZero;
    }
    
    int a = max(MaxIncludingPreviousIncZero,MaxExcludingPreviousIncZero), b = max(MaxIncludingPreviousExZero,MaxExcludingPreviousExZero);
    return max(a,b);
}
