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
    int longest;
    void dfs(TreeNode* root, int cur, int last){
        if (!root){
            longest = max(cur,longest);
            return;
        }
        
        if (root->val == last + 1){
            dfs(root->left,cur+1,root->val);
            dfs(root->right,cur+1,root->val);
        }
        
        else{
            longest = max(cur,longest);
            dfs(root->left,1,root->val);
            dfs(root->right,1,root->val);
        }
    }
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        longest = 0;
        dfs(root->left,1,root->val);
        dfs(root->right,1,root->val);
        return longest;
    }
};
