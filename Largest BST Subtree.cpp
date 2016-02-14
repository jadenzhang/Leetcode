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
    int largestBSTSubtree(TreeNode* root) {
        int ret = 0;
        helper(root,ret);
        return ret;
    }
    
private:
    struct Node{
        int size;
        int min;
        int max;
        bool isBST;
        Node(){
            size = 0;
            min = INT_MAX;
            max = INT_MIN;
            isBST = false;
        }
    };
    
    Node* helper(TreeNode* root, int& ret){
        Node* cur = new Node();
        if (!root){
            cur->isBST = true;
            return cur;
        }
        
        Node* left = helper(root->left, ret);
        Node* right = helper(root->right, ret);
        
        if (left->isBST && root->val>left->max && right->isBST && root->val<right->min){
            cur->isBST = true;
            cur->min = min(root->val,left->min);
            cur->max = max(root->val,right->max);
            cur->size = left->size + right->size + 1;
            if (cur->size > ret) ret = cur->size;
        }
        
        return cur;
    }
};
