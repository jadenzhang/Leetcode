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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size()!=postorder.size()) return NULL;
        int n=inorder.size();
        return build(inorder,postorder,0,n-1,0,n-1);
    }
    
    TreeNode* build(vector<int> &inorder, vector<int> &postorder, int s1, int e1, int s2, int e2){
        if (s1>e1 || s2>e2) return NULL;
        TreeNode* root = new TreeNode(postorder[e2]);
        int rootIndex;
        for (int i=s1;i<=e1;i++){
            if (inorder[i]==root->val){
                rootIndex=i;
                break;
            }
        }
        
        int leftSize = rootIndex - s1;
        int rightSize = e1 - rootIndex;
        root->left=build(inorder,postorder,s1,rootIndex-1,s2,s2+leftSize-1);
        root->right=build(inorder,postorder,rootIndex+1,e1,e2-rightSize,e2-1);
        return root;
    }
};
