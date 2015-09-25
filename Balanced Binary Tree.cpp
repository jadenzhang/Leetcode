/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root==NULL) return true;
        int val=getb(root);
        return val==-1? false:true;
    }
    
    int getb(TreeNode* root){
        if (root==NULL) return 0;
        int left=getb(root->left);
        if (left==-1) return -1;
        int right=getb(root->right);
        if (right==-1) return -1;
        if (abs(right-left)>1) return -1;
        return left>right? left+1:right+1;
    }
};
