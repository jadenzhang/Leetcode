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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while (root){
            s.push(root);
            root=root->left;
        }
        
        while (!s.empty()){
            TreeNode* tem = s.top();
            s.pop();
            if (--k==0) return tem->val;
            else{
                if (tem->right){
                    s.push(tem->right);
                    tem = tem->right;
                    while (tem->left){
                        s.push(tem->left);
                        tem = tem->left;
                    }
                }
            }
        }
        
        // Actually we do not have to return anything here, since there is a guarteen that k is smaller than the number of TreeNodes.
    }
};
