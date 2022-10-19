vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    
    vector<vector<int>> ReturnValue, Bigger;
    int nIntevalSize = intervals.size(), nFirstIndex=0, nFinalIndex=nIntevalSize, a=newInterval[0], b=newInterval[1];
    
    ReturnValue.reserve(nIntevalSize);
    
    
    for(int Index=0; Index<intervals.size(); Index++)
    {
        if(intervals[Index][1] < newInterval[0])
        {
            ReturnValue.push_back(intervals[Index]);
        }
        else if(intervals[Index][0] > newInterval[1])
        {
            Bigger.push_back(intervals[Index]);
        }
        else
        {
            a = min(intervals[Index][0], a);
            b = max(intervals[Index][1], b);
        }
    }
    vector<int> toAdd;
    toAdd.resize(2);
    toAdd[0]=a;
    toAdd[1]=b;
    ReturnValue.push_back(toAdd);
    
    ReturnValue.insert(ReturnValue.end(), Bigger.begin(), Bigger.end());
    
    return ReturnValue;
}

