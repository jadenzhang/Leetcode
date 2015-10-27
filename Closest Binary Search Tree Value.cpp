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
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        if (target>root->val) root=root->right;
        else root=root->left;
        while (root){
            if (target == root->val) return root->val;
            else if (abs(target-root->val)<abs(target-res)) res=root->val;
            
            if (target>root->val) root=root->right;
            else root=root->left;
        }
        
        return res;
    }
};
