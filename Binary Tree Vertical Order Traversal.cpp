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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> res;
        queue<pair<int,TreeNode*>> q;
        if (root) q.push({0,root});
        while (!q.empty()){
            auto temp = q.front();
            q.pop();
            res[temp.first].push_back(temp.second->val);
            if (temp.second->left) q.push({temp.first-1,temp.second->left});
            if (temp.second->right) q.push({temp.first+1,temp.second->right});
        }
        vector<vector<int>> ret;
        for (auto a:res){
            ret.push_back(a.second);
        }
        return ret;
    }
};
