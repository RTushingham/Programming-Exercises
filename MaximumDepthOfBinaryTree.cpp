
#include "leetcode-helpers/TreeNode.h"

#include <algorithm>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if( nullptr == root )
        {
            return 0;
        }
        return std::max( maxDepth( root->left ), maxDepth( root->right ) ) + 1;
    }
};


#include "leetcode-helpers/ParseTree.h"

#include "gtest/gtest.h"

TEST( BinaryTreeMaximumDepthTests, Test )
{
    Solution solution{};

    auto data{ Parse( "1,2,3" ) };
    int expected{ 2 };
    EXPECT_EQ( solution.maxDepth( &data.front() ), expected );

    data = Parse( "-10,9,20,null,null,15,7" );
    expected = 3;
    EXPECT_EQ( solution.maxDepth( &data.front() ), expected );
    
    data = Parse( "3,9,20,null,null,15,7" );
    expected = 3;
    EXPECT_EQ( solution.maxDepth( &data.front() ), expected );
    
    data = Parse( "1,null,2" );
    expected = 2;
    EXPECT_EQ( solution.maxDepth( &data.front() ), expected );
}
