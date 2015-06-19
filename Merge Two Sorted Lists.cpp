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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode  *c1=l1,*c2=l2;
        ListNode* newNode = new ListNode(-1);
        ListNode* cur = newNode;
        
        while (c1&&c2){
            
            if (c1->val > c2->val){
                
                cur->next=c2;
                cur=cur->next;
                c2=c2->next;
            }
            
            else{
                cur->next=c1;
                cur=cur->next;
                c1=c1->next;
            }
        }
        
        if (c1&&!c2) cur->next = c1;
        else if (!c1&&c2) cur->next = c2;
        
        
        return newNode->next;
    }
};
