#include <iostream>

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
    int kthSmallest(TreeNode* root, int k) {
        m_nK = k;
        m_nCount = 0;
        
        AssessIfKthSmallest(root);
        
        return m_nReturnValue;
    }
    
private:
    int m_nK;
    int m_nCount;
    int m_nReturnValue;
    
    void AssessIfKthSmallest(TreeNode* root){
        if(root->left != nullptr)
        {
            AssessIfKthSmallest(root->left);
        }
        
        m_nCount++;
        cout << "root->left: " << root->left << " root->right: " << root->right << " root->val: " << root->val << endl;
        
        cout << "m_nCount: " << m_nCount << endl;
        
        if(m_nCount == m_nK)
        {
            m_nReturnValue = root->val;
        }
        if(m_nCount >= m_nK)
        {
            cout << "m_nReturnValue: " << m_nReturnValue << endl;
                
            return;
        }
        
        if(root->right != nullptr)
        {
            AssessIfKthSmallest(root->right);
        }
    }
};

