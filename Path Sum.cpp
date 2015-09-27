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
    bool hasPathSum(TreeNode* root, int sum) {
        return tool(root,0,sum);
    }
    bool tool(TreeNode* root, int sum, int target){
        if (root==NULL) return false;
        sum += root->val;
        if (root->right==NULL && root->left==NULL ){
            if (sum==target) return true;
            else return false;
        }
        
        return tool(root->right,sum,target) || tool(root->left,sum,target);
    }
};
