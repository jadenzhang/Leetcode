/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        UndirectedGraphNode* real=node;
        UndirectedGraphNode* clone=new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode*> q;
        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> hash;
        q.push(real);
        hash[real]=clone;
        
        while (!q.empty()){
            real = q.front();
            clone = hash[real];
            q.pop();
            for (int i=0;i<real->neighbors.size();i++){
                UndirectedGraphNode* nb=real->neighbors[i];
                if (hash.find(nb) == hash.end()){
                    hash[nb]=new UndirectedGraphNode(nb->label);
                    clone->neighbors.push_back(hash[nb]);
                    q.push(nb);
                }
                else{
                    clone->neighbors.push_back(hash[nb]);
                }
            }
        }
        
        return hash[node];
        
    }
};
