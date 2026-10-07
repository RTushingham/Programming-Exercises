package exercises

// Given an array containing n distinct numbers in the range [0, n], return the only number in the range that is missing.
func missingNumber(nums []int) int {
    // This algorithm is effectively a hash sort just where the hashing is a noop
    //  - this code is imperative
    running_xor := getRunningXor( len( nums ) )

    for _, n := range nums {
        running_xor ^= n
    }
    
    return running_xor
}

