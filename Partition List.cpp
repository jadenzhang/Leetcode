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
    ListNode* partition(ListNode* head, int x) {
        ListNode* h1 = new ListNode(0);
        ListNode* h2 = new ListNode(0);
        ListNode* cur = h1;
        h2->next = head;
        head = h2;
        while (head->next){
            if (head->next->val < x) head = head->next;
            else{
                cur->next = head->next;
                head->next = head->next->next;
                cur = cur->next;
                cur->next = NULL;
            }
        }
        
        head->next = h1->next;
        return h2->next;
    }
};
