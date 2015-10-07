class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL) return NULL;
        TreeNode* tem;
        tem=root->left;
        root->left=root->right;
        root->right=tem;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
