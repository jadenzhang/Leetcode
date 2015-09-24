/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
Recursion:

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return tool(root->left,root->right);
    }
    
    bool tool(TreeNode* left, TreeNode* right){
        
        if (left == NULL) return right==NULL;
        if (right == NULL) return left==NULL;
        if (left->val != right->val) return false;
        if (!tool(left->left,right->right)) return false;
        if (!tool(left->right,right->left)) return false;
        return true;
    }
};
