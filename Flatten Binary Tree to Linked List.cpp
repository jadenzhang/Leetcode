/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return NULL;
        vector<TreeNode*> allnodes;
        preorder(root,allnodes);
        
        for (int i=0;i<allnodes.size()-1;i++){
            allnodes[i]->left=NULL;
            allnodes[i]->right=allnodes[i+1];
        }
        allnodes[allnodes.size()-1]->left=NULL;
        allnodes[allnodes.size()-1]->right=NULL;
        
    }
    
    void preorder(TreeNode* root, vector<TreeNode*> &allnodes){
        if(!root) return;
        allnodes.push_back(root);
        preorder(root->left,allnodes);
        preorder(root->right,allnodes);
    }
    
};*/

class Solution {
public:
    void flatten(TreeNode *root) {
        tool(root);
    }
    
    TreeNode* tool(TreeNode* root){
        if (!root) return NULL;
        TreeNode* leftend=tool(root->left);
        TreeNode* rightend=tool(root->right);
        if (root->left){
            TreeNode* tem=root->right;
            root->right=root->left;
            root->left=NULL;
            leftend->right=tem;
        }
        
        if (rightend) return rightend;
        if (leftend) return leftend;
        return root;
    }

};
