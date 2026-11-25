
from LeetcodeHelpers.TreeNode import TreeNode

# "Solution" exists to make this code identical to a valid solution on Leetcode
class Solution:
    def maxDepth(self, root: TreeNode | None) -> int:
        """
        Return max depth of binary tree.
        """

        if None == root :
            return 0
        
        return max( self.maxDepth( root.left ), self.maxDepth( root.right ) ) + 1


from LeetcodeHelpers.ParseTree import Parse_from_string

import unittest

class TestMaxDepth(unittest.TestCase):

    def test(self):
        solution = Solution()
        
        data = Parse_from_string( "1,2,3" )
        expected = 2
        self.assertEqual( solution.maxDepth( data ), expected )
        
        data = Parse_from_string( "-10,9,20,null,null,15,7" )
        expected = 3
        self.assertEqual( solution.maxDepth( data ), expected )
        
        data = Parse_from_string( "3,9,20,null,null,15,7" )
        expected = 3
        self.assertEqual( solution.maxDepth( data ), expected )
        
        data = Parse_from_string( "1,null,2" )
        expected = 2
        self.assertEqual( solution.maxDepth( data ), expected )

