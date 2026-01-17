vector<int> twoSum(vector<int>& numbers, int target) {
    int first=0, second=numbers.size()-1;
    
    while(first<second)
    {
        int sum = numbers[first] + numbers[second];
        if(sum < target)
        {
            first++;
        }
        else if(sum > target)
        {
            second--;
        }
        else
        {
            return {first+1, second+1};
        }
    }
    return {first+1, second+1};
}

