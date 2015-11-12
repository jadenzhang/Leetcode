/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* cur = head;
        int len = 0;
        while (cur){
            len++;
            cur = cur->next;
        }
        return dfs(head,0,len-1);
    }
    
    TreeNode* dfs(ListNode* &head, int left, int right){
        if (left>right) return NULL;
        int mid = left + (right - left)/2;
        TreeNode* leftchild = dfs(head,left,mid-1);
        TreeNode* root =  new TreeNode(head->val);
        head = head->next;
        TreeNode* rightchild = dfs(head,mid+1,right);
        root->left = leftchild;
        root->right = rightchild;
        return root;
    }
};
