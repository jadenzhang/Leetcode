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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            
            if (temp==NULL){
                if (!q.empty()) q.push(NULL);
            }
            else{
                if (q.front()==NULL) res.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return res;    
    }
};
