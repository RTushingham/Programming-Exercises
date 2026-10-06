import bisect

# "Solution" exists to make this code identical to a valid solution on Leetcode 
class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:
        prevs = []

        for n in nums:
            index = bisect.bisect_left( prevs, n )

            if index == len( prevs ):
                prevs.append( n )
            else:
                prevs[ index ] = n

        return len( prevs )


import unittest

class TestFindDuplicates(unittest.TestCase):

    def test(self):
        solution = Solution()

        # Are these tupples converted into lists when passed to function?
        data = ( 10,9,2,5,3,7,101,18 )
        expected = 4
        self.assertEqual( solution.lengthOfLIS(data), expected )
        
        data = ( 0,1,0,3,2,3 )
        expected = 4
        self.assertEqual( solution.lengthOfLIS(data), expected )
        
        data = ( 7,7,7,7,7,7,7 )
        expected = 1
        self.assertEqual( solution.lengthOfLIS(data), expected )
        
        data = [ 1 ]
        expected = 1
        self.assertEqual( solution.lengthOfLIS(data), expected )
        
        data = ( 1,2 )
        expected = 2
        self.assertEqual( solution.lengthOfLIS(data), expected )

        data = ( 3,5,6,2,5,4,19,5,6,7,12 )
        expected = 6
        self.assertEqual( solution.lengthOfLIS(data), expected )

