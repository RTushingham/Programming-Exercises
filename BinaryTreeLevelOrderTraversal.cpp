
#include "leetcode-helpers/TreeNode.h"

#include <vector>

// std is used as a namespace to make this code identical to a valid solution on Leetcode
using namespace std;

class SolutionRecursive {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> returnValue;

        loop( root, 0, returnValue );

        return returnValue;
    }

private:
    void loop( TreeNode* root, int Level, vector<vector<int>>& returnValue )
    {
        if( nullptr == root)
        {
            return;
        }
        
        if( returnValue.size() <= Level )
        {
            returnValue.push_back( {} );
        }
        returnValue[Level].push_back( root->val );
        
        loop( root->left, Level+1, returnValue );
        loop( root->right, Level+1, returnValue );
    }
};


#include <queue>

class SolutionIterative {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> NextLevel;
        if(root)
        {
            NextLevel.push(root);
        }
        vector<vector<int>> returnValue;
        
        while(!NextLevel.empty())
        {
            int NextLevelSize = NextLevel.size();
            vector<int> thisLevel;
            
            for(int Index=0; Index<NextLevelSize; Index++)
            {
                TreeNode* dummy = NextLevel.front();
                NextLevel.pop();
                thisLevel.push_back(dummy->val);
                if(dummy->left)
                {
                    NextLevel.push(dummy->left);
                }
                if(dummy->right)
                {
                    NextLevel.push(dummy->right);
                }
            }
            returnValue.push_back(thisLevel);
        }
        return returnValue;
    }
};


#include "leetcode-helpers/ParseTree.h"

#include "gtest/gtest.h"

namespace
{
    using AllSolutions = testing::Types<
		SolutionRecursive,
        SolutionIterative
	>;

    template <typename T>
    class BinaryTreeLevelOrderTests : public testing::Test {};

    TYPED_TEST_SUITE( BinaryTreeLevelOrderTests, AllSolutions );
}

TYPED_TEST( BinaryTreeLevelOrderTests, Test )
{
    TypeParam solution{};

    vector<vector<int>> expected{};

    auto data{ Parse( "3,9,20,null,null,15,7" ) };
    expected = { { 3 }, { 9,20 }, { 15,7 } };
    EXPECT_EQ( solution.levelOrder( &data.front() ), expected );

    data = Parse( "1" );
    expected = { { 1 } };
    EXPECT_EQ( solution.levelOrder( &data.front() ), expected );

    data = Parse( "" );
    expected = {};
    EXPECT_EQ( solution.levelOrder( nullptr ), expected );
}
