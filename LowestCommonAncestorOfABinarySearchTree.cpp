
#include "leetcode-helpers/TreeNode.h"

#include <algorithm>

// Iteration method
class SolutionIterative {
public:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int nLarger = std::max(p->val,q->val);
    int nSmaller = std::min(p->val,q->val);
    while(root != nullptr)
    {
        if(root->val > nLarger)
        {
            root = root->left;
        }
        else if(root->val < nSmaller)
        {
            root = root->right;
    	}
        else
        {
            return root;
        }
    }
    return nullptr;
}
};


// recursion using tail call
class SolutionRecursiveTailCall {
public:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr)
    {
        return nullptr;
    }
    else if(root->val > p->val && root->val > q->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    else if(root->val < p->val && root->val < q->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    else
    {
        return root;
    }
}
};


// recursion using wrapper
class SolutionRecursiveWrapper {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        m_nLarger = std::max(p->val,q->val);
        m_nSmaller = std::min(p->val,q->val);
        return LCAIterator(root);
    }
    
private:
    int m_nLarger;
    int m_nSmaller;
    
    TreeNode* LCAIterator(TreeNode* root) {
        if(root == nullptr)
        {
            return nullptr;
        }
        else if(root->val > m_nLarger)
        {
            return LCAIterator(root->left);
        }
        else if(root->val < m_nSmaller)
        {
            return LCAIterator(root->right);
        }
        else
        {
            return root;
        }
    }
};


#include "leetcode-helpers/ParseTree.h"

#include "gtest/gtest.h"

namespace
{
    using AllSolutions = testing::Types<
		SolutionIterative,
        SolutionRecursiveTailCall,
        SolutionRecursiveWrapper
	>;

    template <typename T>
    class LowestCommonAcnestorBSTTests : public testing::Test {};

    TYPED_TEST_SUITE( LowestCommonAcnestorBSTTests, AllSolutions );
}

TYPED_TEST( LowestCommonAcnestorBSTTests, Test )
{
    TypeParam solution{};

    TreeNode* p{};
    TreeNode* q{};
    int expected{};

    auto data{ Parse( "6,2,8,0,4,7,9,null,null,3,5" ) };
    p = &(*(std::find_if( data.begin(), data.end(), []( const auto& a ){ return a.val == 2; } )));
    // p = 2
    q = &(*(std::find_if( data.begin(), data.end(), []( const auto& a ){ return a.val == 8; } )));
    // q = 8
    expected = 6;
    EXPECT_EQ( solution.lowestCommonAncestor( &data.front(), p, q )->val, expected );

    data = Parse( "6,2,8,0,4,7,9,null,null,3,5" );
    p = &(*(std::find_if( data.begin(), data.end(), []( const auto& a ){ return a.val == 2; } )));
    // p = 2
    q = &(*(std::find_if( data.begin(), data.end(), []( const auto& a ){ return a.val == 4; } )));
    // q = 4
    expected = 2;
    EXPECT_EQ( solution.lowestCommonAncestor( &data.front(), p, q )->val, expected );

    data = Parse( "2,1" );
    p = &(*(std::find_if( data.begin(), data.end(), []( const auto& a ){ return a.val == 2; } )));
    // p = 2
    q = &(*(std::find_if( data.begin(), data.end(), []( const auto& a ){ return a.val == 1; } )));
    // q = 1
    expected = 2;
    EXPECT_EQ( solution.lowestCommonAncestor( &data.front(), p, q )->val, expected );
}
