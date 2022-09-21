/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Iteration method
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int nLarger = max(p->val,q->val);
    int nSmaller = min(p->val,q->val);
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

// recursion using tail call
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

// recursion using wrapper
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        m_nLarger = max(p->val,q->val);
        m_nSmaller = min(p->val,q->val);
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
