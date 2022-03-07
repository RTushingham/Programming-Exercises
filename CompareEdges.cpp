#define debug 0

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

	bool CompareEdges(TreeNode* TreeEdge, TreeNode* SubTreeEdge){
        if(SubTreeEdge == nullptr && TreeEdge == nullptr){
            #if debug   
                cout << "CompareEdges - Both Edges are Null." << endl;  
            #endif
            return 1;
        }else if(SubTreeEdge == nullptr ^ TreeEdge == nullptr){
            #if debug   
                cout << "CompareEdges - One Edge is Null." << endl;    
            #endif
            return 0;
        }else if(TreeEdge->val != SubTreeEdge->val){
            #if debug   
                cout << "CompareEdges - Values don't equal." << endl;   
            #endif
            return 0;
        }
        #if debug   
            cout << "CompareEdges - Passed, onto next." << endl;        
        #endif
        return CompareEdges(TreeEdge->left, SubTreeEdge->left) and CompareEdges(TreeEdge->right, SubTreeEdge->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr){
            #if debug   
                cout << "isSubtree - root is null." << endl;        
            #endif
            return 0;
        }
        if(root->val == subRoot->val){
            #if debug  
                cout << "root->val " << root->val << endl;  
                cout << "isSubtree - values are equal." << endl;        
            #endif
            return (CompareEdges(root->left, subRoot->left) and CompareEdges(root->right, subRoot->right)) or isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
        }else{
            #if debug
                cout << "root->val " << root->val << endl; 
                cout << "isSubtree - values are not equal." << endl;        
            #endif
            return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
        }
    }


/*
Test cases used on Leetcode:

[3,4,5,1,2]
[4,1,2]

[3,4,5,1,2,null,null,9,10]
[4,1,2]

[4,4,4,1,2]
[4,1,2]

[3,4,5,1,2,null,null,null,null,0]
[4,1,2]

*/
