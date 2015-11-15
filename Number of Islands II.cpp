class UnionFind{
public:
    UnionFind(int m, int n){
        for (int i=0;i<m*n;i++) {
            islands.push_back(-1);
            sizes.push_back(1);
        }
        row = m;
        col = n;
        count = 0;
    }
    
    int index(int x, int y){
        return x*col+y;
    }
    
    int size(){
        return count;
    }
    
    int id(int x, int y){
        if (x<row && x>=0 && y<col && y>=0) return islands[index(x,y)];
        else return -1;
    }
    
    int add(int x, int y){
        int idx = index(x,y);
        islands[idx] = idx;
        sizes[idx] = 1;
        count++;
        return idx;
    }
    
    int root(int i){
        while (islands[i] != i){
            i = islands[i];
        }
        return i;
    }
    
    int find(int q, int p){
        return root(q)==root(p);
    }
    
    int unite(int q, int p){
        p = root(p);
        q = root(q);
        if (sizes[q]>sizes[p]) swap(q,p);
        islands[q] = p;
        sizes[p] += sizes[q];
        count--;
    }
    
private:
    int row,col,count;
    vector<int> islands,sizes;
    
    
};
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        UnionFind island(m,n);
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<int> ret;
        for (auto pos:positions){
            int x = pos.first, y = pos.second;
            int p = island.add(x,y);
            for (auto d:dir){
                int q = island.id(x+d.first,y+d.second);
                if (q>=0 && !island.find(q,p)){
                    island.unite(q,p);
                }
            }
            ret.push_back(island.size());
        }
        
        return ret;
    }
};
