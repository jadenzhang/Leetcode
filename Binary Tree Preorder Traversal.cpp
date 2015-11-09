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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preorder(ret,root);
        return ret;
    }
    
    void preorder(vector<int> &ret, TreeNode* root){
        if (!root) return;
        ret.push_back(root->val);
        preorder(ret,root->left);
        preorder(ret,root->right);
        
    }
};
