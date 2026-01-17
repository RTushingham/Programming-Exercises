// Given an array containing n distinct numbers in the range [0, n], return the only number in the range that is missing.
func missingNumber(nums []int) int {
    // This algorithm is effectively a hash sort just where the hashing is a noop
    //  - this code is imperative
    nums_contains_indexed := make([]bool, len( nums ) + 1)

    for i := range len( nums ) {
        nums_contains_indexed [nums[i]] = true
    }
    
    for i := range len( nums_contains_indexed ) {
        if nums_contains_indexed [i] == false{
            return i
        }
    }

    return -1
}