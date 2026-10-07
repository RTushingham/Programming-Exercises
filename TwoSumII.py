
# "Solution" class is here to make this code identical to a valid solution on Leetcode
class Solution:
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        first_index = 0
        second_index = len( numbers ) - 1

        while first_index < second_index :
            current_sum = numbers[ first_index ] + numbers[ second_index ]
            if target < current_sum :
                second_index -= 1
            elif target > current_sum :
                first_index += 1
            else :
                break

        return [ first_index + 1, second_index + 1 ]


import unittest

class TestTwoSumII(unittest.TestCase):

    def test_two_sum(self):
        solution = Solution()
        
        data = [ 2,7,11,15 ]
        target = 9
        expected = [ 1,2 ]
        self.assertEqual( solution.twoSum(data,target), expected )
        target = 13
        expected = [ 1,3 ]
        self.assertEqual( solution.twoSum(data,target), expected )
        target = 18
        expected = [ 2,3 ]
        self.assertEqual( solution.twoSum(data,target), expected )
        target = 22
        expected = [ 2,4 ]
        self.assertEqual( solution.twoSum(data,target), expected )
        target = 26
        expected = [ 3,4 ]
        self.assertEqual( solution.twoSum(data,target), expected )

        data = [ 2,3,4 ]
        target = 6
        expected = [ 1,3 ]
        self.assertEqual( solution.twoSum(data,target), expected )

        data = [ 3,3 ]
        target = 6
        expected = [ 1,2 ]
        self.assertEqual( solution.twoSum(data,target), expected )

