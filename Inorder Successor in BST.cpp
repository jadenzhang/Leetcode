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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ret = NULL;;
        if (p->right){
            ret = p->right;
            while (ret->left) ret = ret->left;
            return ret;
        }
        
        TreeNode* q = root;
        while (q->val != p->val){
            if (q->val > p->val){
                ret = q;
                q = q->left;
            }
            else q = q->right;
        }
        
        return ret;
    }
};
