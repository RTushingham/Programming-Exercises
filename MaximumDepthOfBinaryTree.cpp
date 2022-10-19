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
    int maxDepth(TreeNode* root) {
        m_nCurrentMax = 0;
        _do(root, 0);
        return m_nCurrentMax;
    }
    
private:
    int m_nCurrentMax;
    void _do(TreeNode* root, int CurrentDepth)
    {
        if(root != nullptr)
        {
            CurrentDepth++;
            m_nCurrentMax = max(m_nCurrentMax, CurrentDepth);
            _do(root->left, CurrentDepth);
            _do(root->right, CurrentDepth);
        }
    }
};


// idk why this is faster:
int maxDepth(TreeNode* root) {
    if(root == nullptr)
    {
        return 0;
    }
    return max(maxDepth(root->left),maxDepth(root->right))+1;
}
