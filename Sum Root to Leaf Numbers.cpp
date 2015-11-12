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
    int sumNumbers(TreeNode* root) {
        vector<int> nums;
        dfs(0,nums,root);
        int sum = 0;
        for (auto a:nums) sum += a;
        return sum;
    }
    
    void dfs(int num, vector<int> &nums, TreeNode* root){
        if (!root) return;
        num = 10*num + root->val;
        if (!root->left && !root->right) nums.push_back(num);
        dfs(num,nums,root->left);
        dfs(num,nums,root->right);
    }
};
