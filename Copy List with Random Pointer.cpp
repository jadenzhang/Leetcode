/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode* p1 = head;
        RandomListNode* p2 = new RandomListNode(head->label);
        
        unordered_map<RandomListNode*, RandomListNode*> m;
        m[p1] = p2;
        while (p1){
            if (p1->next){
                if (m.count(p1->next)){
                    p2->next = m[p1->next];
                }
                else{
                    p2->next = new RandomListNode(p1->next->label);
                    m[p1->next] = p2->next;
                }
            }
            
            if (p1->random){
                if (m.count(p1->random)){
                    p2->random = m[p1->random];
                }
                else{
                    p2->random = new RandomListNode(p1->random->label);
                    m[p1->random] = p2->random;
                }
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return m[head];
    }
};
