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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        ListNode* guardian = new ListNode(-1);
        guardian->next = head;
        ListNode* pre = guardian;
        int value;
        while(head && head->next){
            if (head->val == head->next->val) 
            {
                value = head->val;
                while (head && head->val == value){
                    pre->next = head->next;
                    head = head->next;
                }
            }
            else{
                pre = head;
                head = head->next;
            } 
        }
        return guardian->next;
    }
};
