
from LeetcodeHelpers.TreeNode import TreeNode

from collections.abc import Generator

def order_traversal( node: TreeNode | None ) -> Generator[int]:
    if None != node.left:
        yield from order_traversal( node.left )
    
    yield node

    if None != node.right:
        yield from order_traversal( node.right )

# "Solution" exists to make this code identical to a valid solution on Leetcode
class Solution:
    def kthSmallest(self, root: TreeNode | None, k: int) -> int:
        """
        Return kth smallest element in Binary Search Tree.
        """
        
        for index, node in enumerate( order_traversal( root ), 1 ):
            if index == k:
                return node.val


from LeetcodeHelpers.ParseTree import Parse_from_string

import unittest

class TestKthSmallest(unittest.TestCase):

    def test(self):
        solution = Solution()
        
        data = Parse_from_string( "3,1,4,null,2" )
        k = 1
        expected = 1
        self.assertEqual( solution.kthSmallest( data, k ), expected )
        
        data = Parse_from_string( "5,3,6,2,4,null,null,1" )
        k = 3
        expected = 3
        self.assertEqual( solution.kthSmallest( data, k ), expected )

