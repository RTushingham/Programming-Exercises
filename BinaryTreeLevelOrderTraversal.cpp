/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        loop(root,0);
        return returnValue;
    }
private:
    vector<vector<int>> returnValue;
    
    void loop(TreeNode* root, int Level)
    {
        if(!root)
        {
            return;
        }
        else
        {
            if( returnValue.size() <= Level)
            {
                returnValue.push_back({});
            }
            returnValue[Level].push_back(root->val);
            
            loop(root->left, ++Level);
            loop(root->right, Level);
        }
    }
};


#include <queue>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
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
