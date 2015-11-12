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
    int maxlen;
    int maxPathSum(TreeNode* root) {
        maxlen = INT_MIN;
        dfs(root);
        return maxlen;
    }
    
    int dfs(TreeNode* root){
        if (!root) return 0;
        int ps_left = max(dfs(root->left),0);
        int ps_right = max(dfs(root->right),0);
        int ps1_root = max(ps_left,ps_right)+root->val;
        int ps2_root = ps_left + ps_right + root->val;
        maxlen = max(ps1_root,max(ps2_root,maxlen));
        return ps1_root;
    }
};
