//#include <iostream>

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
    int maxPathSum(TreeNode* root) {
        m_nMax = root->val;
        
        int nL = MaxFinishingOnSelf(root->left);
        int nR = MaxFinishingOnSelf(root->right);
        
//        cout << "nL, nR, root->val, m_nMax: " << nL << ", " << nR << ", " << root->val << ", " << m_nMax << endl;
        m_nMax = max(m_nMax, root->val + nL + nR);
//        cout << "m_nMax: " << m_nMax << endl;
        
//        cout << "End of Algo" << endl;
        return m_nMax;
    }
    
private:
    int m_nMax;
    int MaxFinishingOnSelf(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        else
        {
            int nL = MaxFinishingOnSelf(root->left);
            int nR = MaxFinishingOnSelf(root->right);
            
//            cout << "nL, nR, root->val, m_nMax: " << nL << ", " << nR << ", " << root->val << ", " << m_nMax << endl;
            m_nMax = max(m_nMax, root->val + nL + nR);
//            cout << "m_nMax: " << m_nMax << endl;
            
//            cout << "return value: " << root->val + max(nL,nR) << endl;
            return max(root->val + max(nL,nR), 0);
        }
    }
};
