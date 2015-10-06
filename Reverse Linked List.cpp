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
    ListNode* reverseList(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode* dummy= new ListNode(0);
        dummy->next = head;
        ListNode* cur = head->next;
        ListNode* record;
        head->next=NULL;
        while(cur){
            record=cur->next;
            cur->next=dummy->next;
            dummy->next=cur;
            cur=record;
        }
        
        return dummy->next;
    }
};
