// Union Find
class Solution {
private:
    int find(vector<int> parent, int i){
        if (parent[i]==-1) return i;
        else return find(parent,parent[i]);
    }
    
    void merge(vector<int>& parent, vector<int>& rank, int u, int v ){
        u = find(parent,u);
        v = find(parent,v);
        
        if (u==v) return;
        if (rank[u]>rank[v]) swap(u,v);
        parent[u]=v;
        if (rank[u]==rank[v]) rank[v]++;
    }
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> parent(n,-1);
        vector<int> rank(n,1);
        
        for (auto edge:edges) merge(parent,rank,edge.first,edge.second);
        
        unordered_set<int> s;
        for (int i=0;i<n;i++) s.insert(find(parent,i));
        return s.size();
    }
};
