func sumSlice(nums []int) int{
    if( len(nums) == 0 ){
        return 0
    } else {
        return nums[0] + sumSlice(nums[1:len(nums)])
    }
}

// Given an array containing n distinct numbers in the range [0, n], return the only number in the range that is missing.
func missingNumber(nums []int) int {
    // This version is functional
    //  - due to go not supporting tail-call optimization it takes up much more memory than my previous procedural version and is slower
    return ((len(nums)+1)*len(nums)/2) - sumSlice(nums)
}