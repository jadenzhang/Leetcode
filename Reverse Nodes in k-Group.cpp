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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head||k<2) return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next = head;
        ListNode* p=dummy;
        while (p->next && p->next->next){
            int i=0;
            ListNode *pre=p->next,*cur=p->next->next;
            while (cur&&i<k-1){
                i++;
                ListNode* tem = cur->next;
                cur->next=pre;
                pre=cur;
                cur=tem;
            }
            
            if (i==(k-1)){
                ListNode* tem = p->next;
                p->next->next = cur;
                p->next = pre;
                p = tem;
            }
            
            else{
                cur = pre->next;
                pre->next = NULL;
                while (cur != p->next){
                    ListNode *tem=cur->next;
                    cur->next=pre;
                    pre=cur;
                    cur=tem;
                }
                break;
            }
        }
        return dummy->next;
    }
};
