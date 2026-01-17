vector<vector<int>> threeSum(vector<int>& nums) {
    
    vector<vector<int>> returnValue;
    
    std::sort(nums.begin(), nums.end());
    
    for(int first=0; first+1 < nums.size(); first++)
    {
        int second = first+1, third = nums.size()-1;
        
        while(second < third)
        {
            int sum = nums[second] + nums[third];
            if(sum < -nums[first])
            {
                second++;
            }
            else if(sum > -nums[first])
            {
                third--;
            }
            else
            {
                vector<int> toPushBack = {nums[first], nums[second], nums[third]};
                returnValue.push_back(toPushBack);
                
                while(second < third && nums[second] == toPushBack[1])
                {
                    second++;
                }
                while(second < third && nums[third] == toPushBack[2])
                {
                    third--;
                }
            }
        }
        
        while(first+1 < nums.size() && nums[first] == nums[first+1])
        {
            first++;
        }
    }
    
    return returnValue;
}

