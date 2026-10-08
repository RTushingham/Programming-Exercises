
#include "leetcode-helpers/TreeNode.h"

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int rank{ 0 };
        int return_value{ 0 };
        
        AssessIfKthSmallest( root, k, rank, return_value );
        
        return return_value;
    }
    
private:    
    void AssessIfKthSmallest( const TreeNode* root, int k, int& rank, int& return_value ){
        if( nullptr != root->left )
        {
            // In-order traversal
            AssessIfKthSmallest( root->left, k, rank, return_value );
        }
        
        rank++;
        
        if( rank == k )
        {
            return_value = root->val;
        }
        if( rank >= k )
        {
            return;
        }
        
        if( nullptr != root->right )
        {
            AssessIfKthSmallest( root->right, k, rank, return_value );
        }
    }
};


#include "leetcode-helpers/ParseTree.h"

#include "gtest/gtest.h"

TEST( KthSmallestElementInBSTTests, Test )
{
    Solution solution{};

    auto data{ Parse( "3,1,4,null,2" ) };
    int k{ 1 };
    int expected{ 1 };
    EXPECT_EQ( solution.kthSmallest( &data.front(), k ), expected );

    data = Parse( "5,3,6,2,4,null,null,1" );
    k = 3;
    expected = 3;
    EXPECT_EQ( solution.kthSmallest( &data.front(), k ), expected );
}
