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
    void recoverTree(TreeNode* root) {
        TreeNode* pre = NULL;
        vector<TreeNode*> t;
        dfs(t,root,pre);
        swap(t.front()->val,t.back()->val);
    }
    
    void dfs(vector<TreeNode*> &t, TreeNode* root, TreeNode* &pre){
        if (!root) return;
        dfs(t,root->left,pre);
        if (pre && pre->val > root->val){
            t.push_back(pre);
            t.push_back(root);
        }
        pre = root;
        dfs(t,root->right,pre);
    }
};
