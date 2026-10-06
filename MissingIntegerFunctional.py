
from RunningXor import getRunningXor

from functools import reduce
from operator import xor

# "Solution" exists to make this code identical to a valid solution on Leetcode
class Solution:
    def missingNumber(self, nums: list[int]) -> list[int]:
        return getRunningXor( len( nums ) ) ^ reduce(xor, nums)


import unittest

class TestMissingIntegerFunctional(unittest.TestCase):

    def test_missing_number_functional(self):
        solution = Solution()
        
        data = ( 3,0,1 )
        expected = 2
        self.assertEqual( solution.missingNumber(data), expected )
        
        data = ( 0,1 )
        expected = 2
        self.assertEqual( solution.missingNumber(data), expected )
        
        data = ( 9,6,4,2,3,5,7,0,1 )
        expected = 8
        self.assertEqual( solution.missingNumber(data), expected )
        
        data = [ 1 ]
        expected = 0
        self.assertEqual( solution.missingNumber(data), expected )
        
        data = [ 1,2 ]
        expected = 0
        self.assertEqual( solution.missingNumber(data), expected )
