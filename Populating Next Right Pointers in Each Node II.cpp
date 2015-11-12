/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode* rootnext = root->next;
        TreeLinkNode* nodenext = NULL;
        while (rootnext){
            if (rootnext->left){
                nodenext = rootnext->left;
                break;
            }
            if (rootnext->right){
                nodenext = rootnext->right;
                break;
            }
            rootnext = rootnext->next;
        }
        
        if (root->right) root->right->next = nodenext;
        if (root->left) root->left->next = root->right? root->right:nodenext;
        connect(root->right);
        connect(root->left);
    }
};
