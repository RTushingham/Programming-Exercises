
#include "leetcode-helpers/TreeNode.h"

#include <algorithm>

class Solution {
    int MaxPathStartingFromNode( const TreeNode* root, int& running_max )
    {
        if( root == nullptr )
        {
            return 0;
        }
        else
        {
            const int l = MaxPathStartingFromNode( root->left, running_max );
            const int r = MaxPathStartingFromNode( root->right, running_max );
            
            // Check  running_max  against  the max path which includes this node and is limited to this subtree
            //   - This will be the  sum of both  of the  max paths starting from  both of the child nodes
            //   - This differs from the value we will  return
            running_max = std::max(
                running_max,
                root->val + l + r
            );
            
            // return  the max path value from this node  or  zero
            //   - The path must be a single line of nodes
            //       - Therefore the max value will be the current value plus the max
            //   - zero  is returned instead of any negative number so that not traversing this path can be simulated by adding the output of this function
            return std::max(
                root->val + std::max( l, r ),
                0
            );
        }
    }

public:
    int maxPathSum( TreeNode* root ) {
        int running_max{};

        MaxPathStartingFromNode( root, running_max );

        return running_max;
    }
};


#include "leetcode-helpers/ParseTree.h"

#include "gtest/gtest.h"

TEST( BinaryTreeMaximumPathSumTests, Test )
{
    Solution solution{};

    auto data{ Parse( "1,2,3" ) };
    int expected{ 6 };
    EXPECT_EQ( solution.maxPathSum( &data.front() ), expected );

    data = Parse( "-10,9,20,null,null,15,7" );
    expected = 42;
    EXPECT_EQ( solution.maxPathSum( &data.front() ), expected );
}
