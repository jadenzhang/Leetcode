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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<pair<double,int>> q;
        vector<int> ret;
        traverse(root,target,k,q);
        while (!q.empty()){
            ret.push_back(q.top().second);
            q.pop();
        }
        
        return ret;
    }
    
    void traverse(TreeNode* root, double target, int k, priority_queue<pair<double,int>> &q){
        if (!root) return;
        q.push(make_pair(abs(target-root->val),root->val));
        if (q.size()>k) q.pop();
        traverse(root->right,target,k,q);
        traverse(root->left,target,k,q);
    }
};
