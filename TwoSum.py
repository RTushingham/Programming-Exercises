
# "Solution" exists to make this code identical to a valid solution on Leetcode
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        previousValuesToIndexes = {}

        for Index in range( len( nums ) ):
            if (target - nums[ Index ]) in previousValuesToIndexes:
                return [ previousValuesToIndexes[ (target - nums[ Index ]) ], Index ]
            elif nums[ Index ] not in previousValuesToIndexes:
                previousValuesToIndexes[ nums[ Index ] ] = Index

        return None


import unittest

class TestTwoSum(unittest.TestCase):

    def test(self):
        solution = Solution()
        
        data = ( 2,7,11,15 )
        k = 9
        expected = [ 0,1 ]
        self.assertEqual( solution.twoSum(data,k), expected )
        k = 17
        expected = [ 0,3 ]
        self.assertEqual( solution.twoSum(data,k), expected )
        k = 18
        expected = [ 1,2 ]
        self.assertEqual( solution.twoSum(data,k), expected )
        
        data = ( 3,2,4 )
        k = 6
        expected = [ 1,2 ]
        self.assertEqual( solution.twoSum(data,k), expected )
        
        data = ( 3,3 )
        k = 6
        expected = [ 0,1 ]
        self.assertEqual( solution.twoSum(data,k), expected )

