class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size()!=n-1) return false;
        vector<int> table(n,-1);
        for (int i=0;i<edges.size();i++){
            int root1=tool(table,edges[i].first);
            int root2=tool(table,edges[i].second);
            if (root1==root2) return false;
            table[root1]=root2;
        }
        return true;
    }
    
    int tool(vector<int> &table, int n){
        if (table[n]==-1) return n;
        else return tool(table,table[n]);
    }
};
