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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> allpaths;
        vector<int> path;
        tool(root,sum,allpaths,path);
        return allpaths;
    }
    
    void tool(TreeNode* root, int sum, vector<vector<int>> &allpaths, vector<int> &path){
        if (!root) return;
        sum -= root->val;
        path.push_back(root->val);
        if(!root->left && !root->right)
        {
            if(sum==0){
                allpaths.push_back(path);
            }
        }
        else
        {
            if (root->left) tool(root->left,sum,allpaths,path);
            if (root->right) tool(root->right,sum,allpaths,path);
        }
        path.pop_back();
    }
};
