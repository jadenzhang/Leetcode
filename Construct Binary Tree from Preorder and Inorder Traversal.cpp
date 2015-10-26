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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()!=inorder.size()) return NULL;
        int n=preorder.size();
        return build(preorder,inorder,0,n-1,0,n-1);
    }
    
    TreeNode* build(vector<int> &preorder, vector<int> &inorder, int s1, int e1, int s2, int e2){
        if (s1>e1 || s2>e2) return NULL;
        TreeNode* root = new TreeNode(preorder[s1]);
        int rootIndex;
        for (int i=s2;i<=e2;i++){
            if (inorder[i]==root->val) 
            {
                rootIndex=i;
                break;
            }
        }
        
        int leftsize = rootIndex - s2;
        int rightsize = e2 - rootIndex;
        
        root->left = build(preorder,inorder,s1+1,s1+leftsize,s2,s2+leftsize-1);
        root->right = build(preorder,inorder,e1-rightsize+1,e1,e2-rightsize+1,e2);
        return root;
    }
};
