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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = new ListNode(INT_MAX);
        pre->next=head;
        ListNode* cur=pre;
        while(cur->next != NULL){
            if(cur->next->val==val) cur->next=cur->next->next;
            else cur=cur->next;
        }
        
        return pre->next;
    }
};
