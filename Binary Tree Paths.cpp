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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        string sol;
        findAllpaths(res,sol,root);
        return res;
    }
    
    void findAllpaths(vector<string> &res, string sol,TreeNode* root){
        int len=sol.length();
        sol+=to_string(root->val);
        if (!root->left&&!root->right) {
            res.push_back(sol);
        }
        else{
            sol+="->";
            if (root->left) findAllpaths(res,sol,root->left);
            if (root->right) findAllpaths(res,sol,root->right);
        }
    }
};
