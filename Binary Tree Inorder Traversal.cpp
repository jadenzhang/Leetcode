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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inorder(ret,root);
        return ret;
    }
    
    void inorder(vector<int> &ret, TreeNode* root){
        if (!root) return;
        inorder(ret,root->left);
        ret.push_back(root->val);
        inorder(ret,root->right);
    }
};
