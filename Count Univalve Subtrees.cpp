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
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return cnt;
        check(root);
        return cnt;
    }
    
    bool check(TreeNode* root){
        if (!root) return true;
        bool left = true, right = true;
        if (root->left) left = check(root->left) && (root->left->val == root->val);
        if (root->right) right = check(root->right) && (root->right->val == root->val);
        if (left&&right){
            cnt++;
            return true;
        }
        return false;
    }
private:
    int cnt = 0;
};
