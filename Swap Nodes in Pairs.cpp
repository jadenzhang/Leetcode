/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if (!head || !head->next) return head;
        
        ListNode *fakedhead = new ListNode(-1);
        fakedhead->next = head;
        
         ListNode *post = fakedhead;
         ListNode *cur = head;
         ListNode *pre = head->next;
         
         while (pre != NULL){
             ListNode* tem = pre->next;
             
             pre->next = cur;
             cur->next = tem;
             post->next = pre;
             
             post = cur;
             if(post->next == NULL) break;
             
             cur = post->next;
             pre = cur->next;
         }
         
         return fakedhead->next;
    }
};
