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
        if (head == NULL) return NULL;
        ListNode* result = head;
        int lastval = head->val;
        while(head != NULL && head->next != NULL ){
            if (head->next->val == lastval){
                head->next = head->next->next;
            }
            
            else{
                lastval = head->next->val;
                head = head->next;
            }
            
        }
        
        return result;
    }
};
