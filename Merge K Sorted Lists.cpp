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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        int n=lists.size();
        while(n>1){
            int gap=(n+1)/2;
            for (int i=0;i<n/2;i++){
                lists[i]=merge(lists[i],lists[i+gap]);
            }
            n=gap;
        }
        return lists[0];
    }
    
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* pre = new ListNode(-1);
        ListNode* cur=pre;
        while (a&&b){
            if (a->val > b->val){
                ListNode* tem=b->next;
                cur->next=b;
                b=tem;
            }
            
            else{
                ListNode* tem=a->next;
                cur->next=a;
                a=tem;
            }
            cur=cur->next;
        }
        if (!a) cur->next=b;
        else cur->next=a;
        
        return pre->next;
    }
};
