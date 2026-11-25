
from operator import itemgetter

# "Solution" exists to make this code identical to a valid solution on Leetcode
class Solution:
    def eraseOverlapIntervals(self, intervals: list[tuple[int,int]]) -> int:
        """
        "eraseOverlapIntervals" finds the smallest number of intervals which can be removed to make the sequence "intervals" a non-overlapping sequence of intervals

        This is equivalent to finding "len(intervals) - the largest non-overlapping subsequence of intervals"
        """

        intervals = sorted(intervals, key=itemgetter(0))

        end = intervals[0][1]
        maximal_non_overlapping_count = 1

        for interval_begin, interval_end in intervals[1:] :
            if interval_end < end :
                end = interval_end
            elif interval_begin >= end :
                end = interval_end
                maximal_non_overlapping_count += 1

        return len(intervals) - maximal_non_overlapping_count


import unittest

class TestEraseOverlapIntervals(unittest.TestCase):

    def test(self):
        solution = Solution()

        data = [[1,2],[2,3],[3,4],[1,3]]
        expected = 1
        self.assertEqual( solution.eraseOverlapIntervals(data), expected )
        
        data = [[1,2],[1,2],[1,2]]
        expected = 2
        self.assertEqual( solution.eraseOverlapIntervals(data), expected )
        
        data = [[1,2],[2,3]]
        expected = 0
        self.assertEqual( solution.eraseOverlapIntervals(data), expected )
        
        data = [[1,3],[5,7],[0,2],[2,6],[6,8]]
        expected = 2
        self.assertEqual( solution.eraseOverlapIntervals(data), expected )

