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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root==NULL) return result;
        int CurrentLevelNode = 1, NextLevelNode=0;
        vector<int> layout;
        int VisitLevelNode = 0;
        queue<TreeNode*> storage;
        storage.push(root);
        
        while(storage.size() > 0){
            TreeNode* node = storage.front();
            storage.pop();
            layout.push_back(node->val);
            VisitLevelNode++;
            
            if (node->left != NULL){
                storage.push(node->left);
                NextLevelNode++;
            }
            if (node->right != NULL){
                storage.push(node->right);
                NextLevelNode++;
            }
            
            if (VisitLevelNode == CurrentLevelNode){
                VisitLevelNode=0;
                CurrentLevelNode=NextLevelNode;
                NextLevelNode=0;
                result.insert(result.begin(),layout);
                layout.clear();
            }
        }
        
        return result;
    }
};
