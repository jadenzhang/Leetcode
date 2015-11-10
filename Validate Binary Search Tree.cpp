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
    bool isValidBST(TreeNode* root) {
        return dfs(root,LONG_MAX,LONG_MIN);
    }
    
    bool dfs(TreeNode* root, long MAX, long MIN){
        if (!root) return true;
        if (root->val < MAX && root->val >MIN && dfs(root->left,root->val,MIN) && dfs(root->right,MAX,root->val)){
            return true;
        }
        else return false;
    }
};
