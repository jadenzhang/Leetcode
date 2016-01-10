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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ret;
        if (!root) return ret;
        stack<int> s;
        vector<int> levelnodes;
        int CurrentNode = 1;
        int level = 1;
        int NextLevelNode = 0;
        while (!q.empty()){
            TreeNode* node = q.front();
            CurrentNode--;
            q.pop();
            if (node->left){
                q.push(node->left);
                NextLevelNode++;
            } 
            if (node->right)
            {
                q.push(node->right);
                NextLevelNode++;
            }
            if (level % 2 != 0){
                levelnodes.push_back(node->val);
            }
            else s.push(node->val);
            
            if (CurrentNode == 0){
                if (level % 2 == 0){
                    while(!s.empty()){
                        levelnodes.push_back(s.top());
                        s.pop();
                    }
                }
                ret.push_back(levelnodes);
                levelnodes.clear();
                CurrentNode = NextLevelNode;
                NextLevelNode = 0;
                level++;
            }
            
        }
        return ret;
    }
};
