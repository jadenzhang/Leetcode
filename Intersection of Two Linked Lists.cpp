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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==NULL || headB==NULL) return NULL;
        ListNode* A=headA;
        ListNode* B=headB;
        bool flagA=false,flagB=false;
        while (true){
            if (flagA==false && A==NULL){
                A=headB;
                flagA=true;
            }
            if (flagB==false && B==NULL){
                B=headA;
                flagB=true;
            }
            if(A==NULL && B==NULL) break;
            if(A==B) return A;
            A=A->next;
            B=B->next;
        }
        
        return NULL;
    }
};
