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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* tail = head;
        int count = 1;
        while (tail->next){ 
            tail = tail->next;
            count++;
        }
        if (count == 2) return head;
        count /= 2;
        ListNode* cur = head;
        ListNode* mark = tail;
        for (int i=0;i<count;i++){
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
            tail->next = temp;
            tail = tail->next;
            tail->next = NULL;
        }
        return head;
    }
};
