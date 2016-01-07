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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        
        while (head){
            ListNode* cur = head;
            ListNode* p = newHead;
            head = head->next;
            while (p->next && p->next->val <= cur->val) p = p->next;
            cur->next = p->next;
            p->next = cur;
        }
        
        return newHead->next;
    }
};
